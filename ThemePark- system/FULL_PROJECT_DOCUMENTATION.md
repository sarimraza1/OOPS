# Theme Park Management System — Complete Project Documentation

> **Source File:** `ThemeParkProject.cpp` (1163 lines, single-file C++ application)  
> **Platform:** Windows (uses `<windows.h>` for console colors)  
> **Compiler:** Any C++11 or later compiler (g++, MSVC)

---

## Table of Contents

1. [Project Overview](#1-project-overview)
2. [Complete Program Flow](#2-complete-program-flow)
3. [Class Architecture & Relationships](#3-class-architecture--relationships)
4. [Every Class in Detail](#4-every-class-in-detail)
5. [OOP Concepts — Where & How Each Is Used](#5-oop-concepts--where--how-each-is-used)
6. [All Features — Staff Portal](#6-all-features--staff-portal)
7. [All Features — Manager Portal](#7-all-features--manager-portal)
8. [Security & Validation Checks](#8-security--validation-checks)
9. [File Handling — Every Data File Explained](#9-file-handling--every-data-file-explained)
10. [Template Functions](#10-template-functions)
11. [Exception Handling — Every Try-Catch & Throw](#11-exception-handling--every-try-catch--throw)
12. [STL Usage (Vectors, Algorithms, Lambdas)](#12-stl-usage)

---

## 1. Project Overview

This is a **console-based Theme Park Management System** built in C++. It simulates a real-world theme park where two types of users (Staff and Manager) can log in and perform role-specific operations. The system manages **visitors, rides, tickets, events, staff members, feedback, and inventory**. All data persists across sessions via pipe-delimited text files.

### Key Characteristics
- **Single file:** Everything is in `ThemeParkProject.cpp` (1163 lines)
- **Role-based access:** Staff and Manager have completely different menus
- **Persistent storage:** 8 text files store all data
- **OOP-heavy:** Inheritance, polymorphism, abstraction, encapsulation, operator overloading, friend functions, static members, templates

### Headers Used (Lines 1–11)
```cpp
#include <algorithm>   // sort(), find_if()
#include <fstream>     // ifstream, ofstream — file I/O
#include <iomanip>     // setprecision(), fixed — formatting decimals
#include <iostream>    // cin, cout — console I/O
#include <sstream>     // stringstream — string parsing/building
#include <stdexcept>   // runtime_error, invalid_argument — exceptions
#include <string>      // string class
#include <vector>      // vector container — dynamic arrays
#include <windows.h>   // Windows console color API
```

---

## 2. Complete Program Flow

### 2.1 Startup Sequence

```
main() [Line 1158-1163]
  └─> ThemeParkSystem app;          // Constructor called
        └─> loadData()              // [Line 984-994] Load ALL 8 files from disk
        │     ├─> loadUsers()       // Users.txt
        │     ├─> loadVisitors()    // Visitors.txt
        │     ├─> loadRides()       // Rides.txt
        │     ├─> loadTickets()     // Tickets.txt
        │     ├─> loadEvents()      // Events.txt
        │     ├─> loadStaff()       // Staff.txt
        │     ├─> loadFeedback()    // Feedback.txt
        │     └─> loadInventory()   // Inventory.txt
        └─> initializeDefaultUsers() // [Line 712-720] Create default users if Users.txt was empty
  └─> app.run();                    // Main loop begins
```

**How it works:** `main()` creates a `ThemeParkSystem` object. The constructor (Line 512-516) immediately calls `loadData()` which reads all 8 text files into vectors in memory. Then `initializeDefaultUsers()` checks if the users vector is empty — if so, it creates a default staff account (`staff1/pass123`) and manager account (`manager1/admin123`) and saves them to `Users.txt`.

### 2.2 Main Menu Loop (Lines 523–559)

```
run() loop:
  ┌──────────────────────────────────┐
  │  THEME PARK MANAGEMENT SYSTEM    │
  │  1. Login as Staff               │
  │  2. Login as Manager             │
  │  0. Exit                         │
  └──────────────────────────────────┘
       │
       ├─ Choice 1 → login("Staff")  → if true → staffPortal()
       ├─ Choice 2 → login("Manager") → if true → managerPortal()
       └─ Choice 0 → saveData() → print goodbye → return (program ends)
```

The `run()` method is an infinite `while(true)` loop. Each iteration:
1. Prints the main menu title in **cyan** using `ConsoleColor::printTitle()`
2. Reads user choice using the template function `readNumber<int>()` (only accepts 0, 1, or 2)
3. The entire switch is wrapped in a `try-catch` block (Lines 535-558) to catch any exceptions
4. On choice 0, `saveData()` writes everything to files, prints a green farewell, and returns

### 2.3 Login Flow (Lines 562–582)

```
login("Staff" or "Manager"):
  1. Prompt for username (getline)
  2. Prompt for password (getline)
  3. Loop through ALL users in the users vector
  4. Check THREE conditions simultaneously:
     - user.getRole() == role        (must match the requested role)
     - user.getUsername() == username (must match entered username)
     - user.authenticate(password)   (must match entered password)
  5. If ALL three match → set currentUser pointer → return true
  6. If NO user matches → print "Invalid credentials" → return false
```

**Security detail:** A staff user CANNOT log into the manager portal even with correct credentials, because the role check (`user.getRole() == role`) will fail. The system checks role, username, AND password together.

### 2.4 Staff Portal Flow (Lines 584–633)

```
staffPortal() loop:
  ┌───────────────────────────┐
  │  === Staff Menu ===       │
  │  1. Register Visitor      │  → addVisitor()
  │  2. View Available Rides  │  → listRides()
  │  3. View Available Events │  → listEvents()
  │  4. Book Ticket           │  → bookTicket()
  │  5. View All Visitors     │  → listVisitors()
  │  6. Logout                │  → set currentUser=nullptr, return
  └───────────────────────────┘
```

### 2.5 Manager Portal Flow (Lines 635–710)

```
managerPortal() loop:
  ┌─────────────────────────────┐
  │  === Manager Menu ===       │
  │  1. Add Staff Member        │  → addStaff()
  │  2. Add Ride                │  → addRide()
  │  3. Add Event               │  → addEvent()
  │  4. Add Inventory Item      │  → addInventory()
  │  5. View Feedback           │  → listFeedback()
  │  6. View Revenue Report     │  → showRevenueReport()
  │  7. View All Staff          │  → listStaff()
  │  8. View All Rides          │  → listRides()
  │  9. View All Events         │  → listEvents()
  │  10. View All Inventory     │  → listInventory()
  │  11. Save Data              │  → saveData()
  │  12. Logout                 │  → saveData(), currentUser=nullptr, return
  └─────────────────────────────┘
```

### 2.6 Ticket Booking Flow (Lines 787–817) — Most Complex Operation

```
bookTicket():
  1. Check visitors and rides vectors are not empty
     └─ If empty → throw runtime_error("Add at least one visitor and one ride first.")
  2. Display all visitors (calls listVisitors())
  3. Prompt for Visitor ID → readNumber<int>(1 to 1000000)
  4. Search visitor by ID using findById<Visitor>(visitors, visitorId) template
     └─ If not found → throw runtime_error("Visitor ID not found.")
  5. Display all rides (calls listRides())
  6. Prompt for Ride ID → readNumber<int>(1 to 1000000)
  7. Search ride by ID using findById<Ride>(rides, rideId) template
     └─ If not found → throw runtime_error("Ride ID not found.")
  8. Check if ride is operational → ride->isOperational()
     └─ If not operational → throw runtime_error("Ride is currently under maintenance.")
  9. Create Ticket object with ride's price
  10. Ask "Apply student discount 10%? (1 Yes, 2 No)"
      └─ If yes → applyDiscount(ticket, 10.0) — friend function modifies private amount
  11. Push ticket into tickets vector
  12. Print ticket using overloaded << operator (friend ostream operator)
```

### 2.7 Shutdown Sequence

```
When user chooses Exit (choice 0 in main menu):
  1. saveData() is called explicitly [Line 548]
  2. Farewell message printed in green
  3. run() returns to main()
  4. main() returns 0
  5. ThemeParkSystem destructor called [Line 518-521]
     └─> saveData() called again (safe — just overwrites same files)
```

**Double-save safety:** Data is saved both when the user exits AND when the destructor runs, ensuring no data loss even if the program exits unexpectedly after the explicit save.

---

## 3. Class Architecture & Relationships

### 3.1 Class Hierarchy Diagram

```
                    ParkEntity (Abstract Base Class)
                   /     |      \        \          \
              Visitor   Ride    Event    Staff    Inventory
                          |
                       Ticket (standalone, uses Ride's price)
                          |
                       Feedback (standalone, uses Visitor's ID)

              User (standalone authentication class)

              ConsoleColor (utility class — static methods only)

              ThemeParkSystem (main system — COMPOSES all other classes)
```

### 3.2 Relationship Types

| Relationship | From → To | Type | Explanation | Lines |
|---|---|---|---|---|
| **Inheritance** | Visitor → ParkEntity | IS-A | Visitor is a ParkEntity | 108 |
| **Inheritance** | Ride → ParkEntity | IS-A | Ride is a ParkEntity | 150 |
| **Inheritance** | Event → ParkEntity | IS-A | Event is a ParkEntity | 255 |
| **Inheritance** | Staff → ParkEntity | IS-A | Staff is a ParkEntity | 307 |
| **Inheritance** | Inventory → ParkEntity | IS-A | Inventory is a ParkEntity | 410 |
| **Composition** | ThemeParkSystem → vectors | HAS-A (owns) | System owns all data vectors | 491–498 |
| **Aggregation** | Ticket → Visitor | USES | Ticket stores visitorId (not the object) | 196 |
| **Aggregation** | Ticket → Ride | USES | Ticket stores rideId (not the object) | 197 |
| **Aggregation** | Feedback → Visitor | USES | Feedback stores visitorId | 353 |
| **Association** | ThemeParkSystem → User | USES (pointer) | currentUser points to logged-in user | 509 |

### 3.3 Composition vs Aggregation

**Composition (Lines 491–498):** `ThemeParkSystem` contains `vector<Visitor>`, `vector<Ride>`, etc. as direct members. When `ThemeParkSystem` is destroyed, ALL vectors and their contents are destroyed. The parts cannot exist without the whole.

**Aggregation (Lines 196–197, 353):** `Ticket` stores `visitorId` and `rideId` as integers — references to `Visitor` and `Ride` objects. The Ticket doesn't own or destroy the Visitor/Ride. Similarly, `Feedback` stores `visitorId` without owning the Visitor.

---

## 4. Every Class in Detail

### 4.1 ConsoleColor (Lines 16–59) — Utility Class

**Purpose:** Provides colored console output on Windows.

**Members:**
- `enum Color` — defines BLACK(0), CYAN(3), GREEN(2), RED(4), WHITE(7) as Windows console color codes

**Methods (ALL static):**
| Method | Lines | Purpose |
|---|---|---|
| `setColor(Color)` | 28–32 | Gets Windows console handle via `GetStdHandle()`, sets text color via `SetConsoleTextAttribute()` |
| `reset()` | 34–37 | Resets to WHITE by calling `setColor(WHITE)` |
| `printTitle(string)` | 39–44 | Prints text in CYAN then resets — used for menu titles |
| `printSuccess(string)` | 46–51 | Prints text in GREEN then resets — used for success messages |
| `printError(string)` | 53–58 | Prints text in RED then resets — used for error messages |

**OOP concept:** All methods are `static` — called on the class itself (`ConsoleColor::printTitle()`), no object needed.

---

### 4.2 ParkEntity (Lines 89–105) — Abstract Base Class

**Purpose:** Defines the common interface for all park entities (visitors, rides, events, staff, inventory).

**Members:**
| Member | Access | Type | Purpose |
|---|---|---|---|
| `id` | `protected` | `int` | Unique identifier — accessible to derived classes directly |
| `name` | `protected` | `string` | Entity name — accessible to derived classes directly |

**Methods:**
| Method | Lines | Purpose |
|---|---|---|
| `ParkEntity(int, string)` | 97 | Constructor — initializes id and name via initializer list |
| `virtual ~ParkEntity()` | 98 | Virtual destructor — ensures proper cleanup when deleting via base pointer |
| `getId() const` | 100 | Getter for id (public access to protected member) |
| `getName() const` | 101 | Getter for name |
| `virtual void display() const = 0` | 103 | **Pure virtual** — makes class abstract, forces all derived classes to implement |
| `virtual string serialize() const = 0` | 104 | **Pure virtual** — forces all derived classes to provide serialization for file saving |

**Why it's abstract:** The two `= 0` pure virtual functions mean you CANNOT create a `ParkEntity` object directly. Every derived class MUST implement both `display()` and `serialize()`.

---

### 4.3 Visitor (Lines 107–147) — Derived from ParkEntity

**Purpose:** Represents a theme park visitor.

**Private Members (Encapsulation):**
| Member | Type | Purpose |
|---|---|---|
| `age` | `int` | Visitor's age |
| `email` | `string` | Visitor's email address |
| `nextId` | `static int` | Auto-incrementing ID counter, starts at 1 (Line 147) |

**Constructors:**
1. **3-parameter** (Line 116–117): `Visitor(name, age, email)` — used when creating NEW visitors. Auto-assigns `nextId++` as the ID.
2. **4-parameter** (Line 119–124): `Visitor(id, name, age, email)` — used when LOADING from file. Takes explicit ID and updates `nextId` if needed (`if (id >= nextId) nextId = id + 1`) to prevent ID collisions.

**Methods:**
| Method | Lines | What It Does |
|---|---|---|
| `getAge()` | 128 | Returns age |
| `getEmail()` | 129 | Returns email |
| `display() const override` | 131–137 | Prints: `Visitor ID: X | Name: Y | Age: Z | Email: W` |
| `serialize() const override` | 139–144 | Returns: `id|name|age|email` for file storage |

**Static member initialization:** `int Visitor::nextId = 1;` (Line 147) — all visitors share this counter.

---

### 4.4 Ride (Lines 149–189) — Derived from ParkEntity

**Purpose:** Represents a theme park ride.

**Private Members:**
| Member | Type | Purpose |
|---|---|---|
| `price` | `double` | Cost per ticket for this ride |
| `operational` | `bool` | `true` = operational, `false` = maintenance |
| `nextId` | `static int` | Auto-ID counter, starts at 1 (Line 189) |

**Constructors:** Same dual-constructor pattern as Visitor.

**Methods:**
| Method | Lines | What It Does |
|---|---|---|
| `getPrice()` | 170 | Returns ride price |
| `isOperational()` | 171 | Returns operational status |
| `display() const override` | 173–179 | Prints ride info, shows "Operational" or "Maintenance" using ternary |
| `serialize() const override` | 181–186 | Returns: `id|name|price|0or1` |

**Display uses ternary operator (Line 178):**
```cpp
(operational ? "Operational" : "Maintenance")
```

---

### 4.5 Ticket (Lines 191–252) — Standalone Class

**Purpose:** Represents a ticket purchase linking a visitor to a ride.

**Private Members:**
| Member | Type | Purpose |
|---|---|---|
| `id` | `int` | Ticket ID |
| `visitorId` | `int` | Links to which Visitor bought it |
| `rideId` | `int` | Links to which Ride it's for |
| `amount` | `double` | Price paid (may be discounted) |
| `nextId` | `static int` | Starts at 1001 (Line 235) — tickets have different ID range |

**Operator Overloading (Lines 227–228):**
```cpp
double operator+(const Ticket &other) const { return amount + other.amount; }
bool operator<(const Ticket &other) const { return amount < other.amount; }
```
- `operator+` — adds two ticket amounts together, returns a double
- `operator<` — compares tickets by price, used by `sort()` in `listTickets()` (Line 913)

**Friend Declarations (Lines 231–232):**
```cpp
friend void applyDiscount(Ticket &ticket, double percentage);
friend ostream &operator<<(ostream &os, const Ticket &ticket);
```

**Friend Function — applyDiscount (Lines 237–243):**
```cpp
void applyDiscount(Ticket &ticket, double percentage) {
    if (percentage < 0 || percentage > 100)
        throw invalid_argument("Discount must be between 0 and 100.");
    ticket.amount -= ticket.amount * (percentage / 100.0);
}
```
This is a **friend function** — it's NOT a member of Ticket, but it can directly access `ticket.amount` (private member). It validates the percentage and throws `invalid_argument` if out of range.

**Friend Stream Operator — operator<< (Lines 245–252):**
```cpp
ostream &operator<<(ostream &os, const Ticket &ticket) {
    os << "Ticket ID: " << ticket.id
       << " | Visitor ID: " << ticket.visitorId
       << " | Ride ID: " << ticket.rideId
       << " | Amount: $" << fixed << setprecision(2) << ticket.amount;
    return os;
}
```
This is a **friend** of Ticket — accesses `ticket.id`, `ticket.visitorId`, `ticket.rideId`, `ticket.amount` directly. Used when you write `cout << ticket`.

---

### 4.6 Event (Lines 254–304) — Derived from ParkEntity

**Purpose:** Represents a scheduled park event with limited capacity.

**Private Members:**
| Member | Type | Purpose |
|---|---|---|
| `date` | `string` | Event date in YYYY-MM-DD format |
| `capacity` | `int` | Maximum attendees allowed |
| `registered` | `int` | Current number registered |
| `nextId` | `static int` | Starts at 2001 (Line 304) |

**Key Method — registerVisitor (Lines 280–286):**
```cpp
void registerVisitor() {
    if (registered < capacity)
        registered++;
    else
        throw runtime_error("Event is full.");
}
```
Checks capacity before incrementing. Throws exception if event is at capacity.

---

### 4.7 Staff (Lines 306–346) — Derived from ParkEntity

**Purpose:** Represents a park employee (different from User — Staff is the employee record, User is the login account).

**Private Members:**
| Member | Type | Purpose |
|---|---|---|
| `role` | `string` | Job role (Manager/Operator/Guide) |
| `salary` | `double` | Monthly salary |
| `nextId` | `static int` | Starts at 3001 (Line 346) |

---

### 4.8 Feedback (Lines 348–407) — Standalone Class

**Purpose:** Stores visitor feedback with ratings.

**Private Members:**
| Member | Type | Purpose |
|---|---|---|
| `id` | `int` | Feedback ID |
| `visitorId` | `int` | Which visitor left it |
| `rating` | `int` | Rating 1–5 |
| `comment` | `string` | Text comment |
| `nextId` | `static int` | Starts at 5001 (Line 395) |

**Friend Function — calculateAverageRating (Lines 397–407):**
```cpp
double calculateAverageRating(const vector<Feedback> &feedbacks) {
    if (feedbacks.empty()) return 0.0;
    double sum = 0.0;
    for (const auto &f : feedbacks)
        sum += f.rating;
    return sum / feedbacks.size();
}
```
This friend function accesses `f.rating` (private) directly. Uses `std::accumulate` with a **lambda function** to sum all ratings, then divides by count.

---

### 4.9 Inventory (Lines 409–456) — Derived from ParkEntity

**Purpose:** Tracks park inventory items (food, merchandise).

**Private Members:**
| Member | Type | Purpose |
|---|---|---|
| `quantity` | `int` | Current stock count |
| `costPerItem` | `double` | Unit cost |
| `nextId` | `static int` | Starts at 4001 (Line 456) |

**Key Method — updateQuantity (Lines 433–438):**
```cpp
void updateQuantity(int change) {
    if (quantity + change < 0)
        throw runtime_error("Insufficient inventory.");
    quantity += change;
}
```
Validates that stock won't go negative before updating.

---

### 4.10 User (Lines 458–485) — Authentication Class

**Purpose:** Represents a system login account (Staff or Manager).

**Protected Members:**
| Member | Type | Purpose |
|---|---|---|
| `userId` | `int` | User account ID |
| `username` | `string` | Login username |
| `password` | `string` | Login password (stored as plain text) |
| `role` | `string` | "Manager" or "Staff" |

**Key Method — authenticate (Line 477):**
```cpp
bool authenticate(const string &pwd) const { return password == pwd; }
```
Simple string comparison — returns true if password matches.

---

### 4.11 ThemeParkSystem (Lines 487–1156) — Main System Class

**Purpose:** The central controller that owns ALL data and provides ALL functionality.

**Private Data Members (Lines 491–509):**
```cpp
vector<Visitor> visitors;       // All registered visitors
vector<Ride> rides;             // All park rides
vector<Ticket> tickets;         // All booked tickets
vector<Event> events;           // All scheduled events
vector<Staff> staff;            // All employee records
vector<Feedback> feedbacks;     // All visitor feedback
vector<Inventory> inventory;    // All inventory items
vector<User> users;             // All login accounts
User *currentUser = nullptr;    // Pointer to currently logged-in user
```

**File name constants (Lines 500–507):**
```cpp
const string visitorsFile = "Visitors.txt";
const string ridesFile = "Rides.txt";
const string ticketsFile = "Tickets.txt";
const string eventsFile = "Events.txt";
const string staffFile = "Staff.txt";
const string feedbackFile = "Feedback.txt";
const string inventoryFile = "Inventory.txt";
const string usersFile = "Users.txt";
```

---

## 5. OOP Concepts — Where & How Each Is Used

### 5.1 Inheritance (IS-A Relationship)

**What it is:** A class (child/derived) inherits members and methods from another class (parent/base).

**Where used — 5 places:**

| Derived Class | Base Class | Line | Declaration |
|---|---|---|---|
| `Visitor` | `ParkEntity` | 108 | `class Visitor : public ParkEntity` |
| `Ride` | `ParkEntity` | 150 | `class Ride : public ParkEntity` |
| `Event` | `ParkEntity` | 255 | `class Event : public ParkEntity` |
| `Staff` | `ParkEntity` | 307 | `class Staff : public ParkEntity` |
| `Inventory` | `ParkEntity` | 410 | `class Inventory : public ParkEntity` |

**How it works:** All 5 derived classes inherit `id`, `name`, `getId()`, and `getName()` from `ParkEntity`. They each add their own private data and implement the two pure virtual functions.

**Constructor chaining example (Line 117):**
```cpp
Visitor(const string &name, int age, const string &email)
    : ParkEntity(nextId++, name), age(age), email(email) {}
```
The `: ParkEntity(nextId++, name)` calls the base class constructor first, then initializes the derived class members.

---

### 5.2 Polymorphism (Runtime + Compile-time)

#### Runtime Polymorphism (Dynamic Dispatch)

**What it is:** Calling a virtual function through a base-class pointer invokes the DERIVED class's version at runtime.

**Where declared (Lines 103–104):**
```cpp
virtual void display() const = 0;
virtual string serialize() const = 0;
```

**Where USED — in every `list` function:** The `listVisitors()`, `listRides()`, `listEvents()`, `listStaff()`, and `listInventory()` methods all demonstrate polymorphism identically.

**Example — listVisitors() (Lines 819–834):**
```cpp
void listVisitors() const {
    vector<const ParkEntity *> entities;    // Vector of BASE class pointers
    for (const auto &v : visitors)
        entities.push_back(&v);             // Store DERIVED (Visitor) addresses

    for (const auto *e : entities)
        e->display();                       // Calls Visitor::display(), NOT ParkEntity::display()
}
```
Even though `e` is a `ParkEntity*`, `e->display()` calls `Visitor::display()` because `display()` is virtual and the actual object is a `Visitor`. This is **runtime polymorphism** — the correct function is selected at runtime based on the actual object type.

**Same pattern in:**
- `listRides()` — Lines 836–851 — calls `Ride::display()`
- `listEvents()` — Lines 853–868 — calls `Event::display()`
- `listStaff()` — Lines 870–885 — calls `Staff::display()`
- `listInventory()` — Lines 887–902 — calls `Inventory::display()`

#### Compile-time Polymorphism (Templates + Overloading)

- **Function templates** `readNumber<T>()` and `findById<T>()` (Lines 62–87) — same function works with different types
- **Operator overloading** in Ticket class: `operator+`, `operator<`, `operator<<` (Lines 227–252)

---

### 5.3 Abstraction

**What it is:** Hiding complex implementation behind a simple interface. Pure virtual functions force an interface without providing implementation.

**Where used (Lines 103–104):**
```cpp
virtual void display() const = 0;     // No body — derived classes MUST implement
virtual string serialize() const = 0; // No body — derived classes MUST implement
```

**Effect:** `ParkEntity` defines WHAT must be done (display and serialize), but not HOW. Each derived class provides its own implementation. The calling code (e.g., `e->display()`) doesn't need to know which specific class it's dealing with.

**Result:** You CANNOT do `ParkEntity p(1, "test");` — compiler error because abstract class.

---

### 5.4 Encapsulation

**What it is:** Hiding internal data and exposing it only through controlled public methods (getters/setters).

**Where used — EVERY class.** Example with Visitor (Lines 108–145):

```
PRIVATE (hidden):          PUBLIC (controlled access):
  int age;           →       int getAge() const { return age; }
  string email;      →       string getEmail() const { return email; }
  static int nextId; →       (no public access — only used internally)
```

**Key design:** There are NO setter methods anywhere. Once an object is created, its data cannot be changed from outside the class. The only exception is `Inventory::updateQuantity()` which modifies `quantity` with validation.

**Protected access in ParkEntity (Lines 92–94):**
```cpp
protected:
    int id;
    string name;
```
`protected` means derived classes (Visitor, Ride, etc.) can access `id` and `name` directly, but outside code cannot.

---

### 5.5 Operator Overloading

**Where used — Ticket class (Lines 227–252):**

| Operator | Line | Type | What It Does |
|---|---|---|---|
| `operator+` | 227 | Member function | Adds amounts of two tickets: `ticket1 + ticket2` returns a double |
| `operator<` | 228 | Member function | Compares ticket prices: used by `sort()` on Line 913 |
| `operator<<` | 245–252 | Friend function | Enables `cout << ticket` — prints formatted ticket details |

**How operator< enables sorting (Line 913):**
```cpp
sort(tickets.begin(), tickets.end());  // Uses operator< to compare Tickets
```
`std::sort` calls `operator<` on pairs of Ticket objects to determine their order.

---

### 5.6 Friend Functions

**What it is:** A function that is NOT a member of a class but is granted access to its private members.

**3 friend functions in the project:**

| Function | Friend Of | Lines | What Private Member It Accesses |
|---|---|---|---|
| `applyDiscount()` | `Ticket` | 231, 237–243 | `ticket.amount` — modifies it directly |
| `operator<<()` | `Ticket` | 232, 245–252 | `ticket.id`, `ticket.visitorId`, `ticket.rideId`, `ticket.amount` |
| `calculateAverageRating()` | `Feedback` | 392, 397–407 | `f.rating` — reads it directly in lambda |

---

### 5.7 Static Members

**What it is:** A variable shared by ALL objects of a class. Only one copy exists regardless of how many objects are created.

| Class | Static Member | Initial Value | Line (Declaration) | Line (Definition) |
|---|---|---|---|---|
| `Visitor` | `nextId` | 1 | 113 | 147 |
| `Ride` | `nextId` | 1 | 155 | 189 |
| `Ticket` | `nextId` | 1001 | 199 | 235 |
| `Event` | `nextId` | 2001 | 261 | 304 |
| `Staff` | `nextId` | 3001 | 312 | 346 |
| `Feedback` | `nextId` | 5001 | 356 | 395 |
| `Inventory` | `nextId` | 4001 | 415 | 456 |

**ID ranges by design:**
- Visitors: 1, 2, 3, ...
- Rides: 1, 2, 3, ...
- Tickets: 1001, 1002, 1003, ...
- Events: 2001, 2002, 2003, ...
- Staff: 3001, 3002, 3003, ...
- Inventory: 4001, 4002, 4003, ...
- Feedback: 5001, 5002, 5003, ...

**How auto-increment works:** The 3-parameter constructor uses `nextId++` in the initializer list. Example (Line 117):
```cpp
: ParkEntity(nextId++, name)  // Uses current nextId as ID, then increments for next object
```

---

### 5.8 Virtual Destructor

**Where (Line 98):** `virtual ~ParkEntity() {}`

**Why:** When you delete a derived class object through a base class pointer (`ParkEntity* p = new Visitor(...); delete p;`), the virtual destructor ensures the DERIVED class destructor runs too, preventing memory leaks.

---

## 6. All Features — Staff Portal

Staff users can perform 5 operations plus logout:

### 6.1 Register Visitor (Lines 723–734)
**What happens:**
1. Prompts for name (string via `getline`)
2. Prompts for age (int, validated 1–120 via `readNumber<int>`)
3. Prompts for email (string via `getline`)
4. Creates `Visitor` object using 3-param constructor (auto-assigns ID)
5. Adds to `visitors` vector via `emplace_back`
6. Prints green success message

### 6.2 View Available Rides (Lines 836–851)
Calls `listRides()`. Creates a `vector<const ParkEntity*>`, fills it with pointers to Ride objects, then calls `display()` on each — demonstrating **runtime polymorphism**.

### 6.3 View Available Events (Lines 853–868)
Same pattern as listRides but for events.

### 6.4 Book Ticket for Visitor (Lines 787–817)
The most complex staff operation. Full flow documented in Section 2.6 above. Involves:
- Template function `findById<T>`
- Friend function `applyDiscount`
- Operator overloading `operator<<`
- Exception handling (3 possible throws)

### 6.5 View All Visitors (Lines 819–834)
Displays all registered visitors using polymorphism through base pointers.

### 6.6 Logout (Line 621–624)
Sets `currentUser = nullptr` and returns to main menu.

---

## 7. All Features — Manager Portal

Managers can perform 11 operations plus logout:

### 7.1 Add Staff Member (Lines 762–773)
Prompts for name, role (Manager/Operator/Guide), and salary (0–100000). Creates Staff object and adds to vector.

### 7.2 Add Ride (Lines 736–747)
Prompts for name, price (0–10000), and status (1=Operational, 2=Maintenance). Creates Ride and adds to vector.

### 7.3 Add Event (Lines 749–760)
Prompts for name, date (YYYY-MM-DD format), and capacity (1–10000). Creates Event and adds to vector.

### 7.4 Add Inventory Item (Lines 775–785)
Prompts for item name, quantity (0–100000), and cost per item (0–1000). Creates Inventory and adds to vector.

### 7.5 View Feedback (Lines 919–932)
Displays ALL feedback entries, then calculates and shows the **average rating** using the friend function `calculateAverageRating()`.

### 7.6 View Revenue Report (Lines 934–942)
```cpp
double revenue = 0.0;
for (const auto &t : tickets)
    revenue += t.getAmount();
```
Iterates through all booked tickets and sums their amounts. Displays as `Total Ticket Revenue: $X.XX`.

### 7.7–7.10 View All Staff/Rides/Events/Inventory
Each uses the same polymorphic pattern: create `vector<const ParkEntity*>`, push derived objects, call `display()`.

### 7.11 Save Data (Line 694)
Manually triggers `saveData()` which writes ALL 8 files. Prints green confirmation.

### 7.12 Logout (Lines 697–701)
Saves data, sets `currentUser = nullptr`, returns to main menu.

---

## 8. Security & Validation Checks

### 8.1 Authentication Security

**Role-based access control (Lines 562–582):**
- Staff credentials CANNOT access Manager portal — the `login()` function checks `user.getRole() == role`
- Three conditions must ALL be true: correct role + correct username + correct password
- Failed login returns `false` — no error thrown, just "Invalid credentials" message

**Credential storage (Users.txt):**
```
1001|staff1|pass123|Staff
2001|manager1|admin123|Manager
```
Passwords are stored as plain text (simple academic project).

### 8.2 Input Validation — readNumber<T> Template (Lines 62–78)

```cpp
template <typename T>
T readNumber(const string &prompt, T minValue, T maxValue) {
    T value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= minValue && value <= maxValue) {
            cin.ignore(10000, '\n');
            return value;
        }
        cout << "Invalid input. Try again.\n";
        cin.clear();                                          // Clear error flags
        cin.ignore(10000, '\n');   // Flush bad input
    }
}
```

**What it validates:**
1. **Type correctness** — `cin >> value` fails if you type letters for an int field
2. **Range check** — value must be between `minValue` and `maxValue` inclusive
3. **Buffer cleanup** — `cin.clear()` resets error flags, `cin.ignore()` flushes remaining garbage
4. **Infinite retry** — loops until valid input is provided (cannot crash)

**Where used with what ranges:**

| Context | Type | Min | Max | Lines |
|---|---|---|---|---|
| Main menu choice | `int` | 0 | 2 | 533 |
| Staff menu choice | `int` | 1 | 6 | 600 |
| Manager menu choice | `int` | 1 | 12 | 657 |
| Visitor age | `int` | 1 | 120 | 728 |
| Ride price | `double` | 0.0 | 10000.0 | 742 |
| Ride status | `int` | 1 | 2 | 743 |
| Event capacity | `int` | 1 | 10000 | 756 |
| Staff salary | `double` | 0.0 | 100000.0 | 769 |
| Inventory quantity | `int` | 0 | 100000 | 780 |
| Cost per item | `double` | 0.0 | 1000.0 | 781 |
| Visitor ID (booking) | `int` | 1 | 1000000 | 793 |
| Ride ID (booking) | `int` | 1 | 1000000 | 800 |
| Discount choice | `int` | 1 | 2 | 810 |

### 8.3 Business Logic Validation

| Check | Where | Line | Exception Thrown |
|---|---|---|---|
| Visitors/rides must exist before booking | `bookTicket()` | 789–790 | `runtime_error("Add at least one visitor and one ride first.")` |
| Visitor ID must exist | `bookTicket()` | 796–797 | `runtime_error("Visitor ID not found.")` |
| Ride ID must exist | `bookTicket()` | 803–804 | `runtime_error("Ride ID not found.")` |
| Ride must be operational | `bookTicket()` | 805–806 | `runtime_error("Ride is currently under maintenance.")` |
| Discount must be 0–100% | `applyDiscount()` | 239–240 | `invalid_argument("Discount must be between 0 and 100.")` |
| Event must not be full | `Event::registerVisitor()` | 282–285 | `runtime_error("Event is full.")` |
| Inventory can't go negative | `Inventory::updateQuantity()` | 435–436 | `runtime_error("Insufficient inventory.")` |

### 8.4 ID Collision Prevention

Every class with a static `nextId` has a safeguard in the file-loading constructor:
```cpp
if (id >= nextId) nextId = id + 1;
```
This ensures that when data is loaded from files, the auto-increment counter jumps past the highest loaded ID. New objects will never get a duplicate ID.

---

## 9. File Handling — Every Data File Explained

### 9.1 File Format

ALL files use **pipe-delimited** (`|`) text format. Each line = one record. Empty lines are skipped during loading.

### 9.2 Each File in Detail

#### Visitors.txt — Lines 946–948 (save), 996–1013 (load)
**Format:** `id|name|age|email`
**Sample:**
```
1|Abbas|28|abbas@email.com
2|Taher|25|taher@email.com
3|Fatima|22|fatima@email.com
```
**Save (Line 946–948):** Opens file with `ofstream`, loops through `visitors` vector, calls `v.serialize()` and writes each line.
**Load (Lines 996–1013):** Opens with `ifstream`, reads line by line with `getline`, splits on `|` using `stringstream`, creates `Visitor` with 4-param constructor.

#### Rides.txt — Lines 950–952 (save), 1016–1033 (load)
**Format:** `id|name|price|operational(0or1)`
**Sample:**
```
1|Roller Coaster|150.00|1
2|Ferris Wheel|100.00|1
3|Bumper Cars|75.00|1
```
**Note:** `operational` is stored as `1` (true) or `0` (false). On load (Line 1032): `statusStr == "1"` converts back to bool.

#### Tickets.txt — Lines 954–956 (save), 1036–1053 (load)
**Format:** `id|visitorId|rideId|amount`
**Sample:**
```
1001|1|1|150.00
1002|2|2|100.00
```

#### Events.txt — Lines 958–960 (save), 1056–1074 (load)
**Format:** `id|name|date|capacity|registered`
**Sample:**
```
2001|Eid Festival|2026-04-29|500|150
2002|Bake Sale|2026-05-03|200|50
```

#### Staff.txt — Lines 962–964 (save), 1077–1094 (load)
**Format:** `id|name|role|salary`
**Sample:**
```
3001|Hassan Ali|Manager|45000.00
3002|Amina Khan|Operator|25000.00
```

#### Feedback.txt — Lines 966–968 (save), 1097–1114 (load)
**Format:** `id|visitorId|rating|comment`
**Sample:**
```
5001|1|5|Amazing experience! Worth every penny
5002|2|4|Great rides, but lines were long
```

#### Inventory.txt — Lines 970–972 (save), 1117–1134 (load)
**Format:** `id|itemName|quantity|costPerItem`
**Sample:**
```
4001|Popcorn|150|2.50
4002|Ice Cream|200|1.50
```

#### Users.txt — Lines 977–982 (save), 1137–1154 (load)
**Format:** `userId|username|password|role`
**Sample:**
```
1001|staff1|pass123|Staff
2001|manager1|admin123|Manager
```

### 9.3 Save Mechanism (Lines 944–982)

`saveData()` opens ALL 7 data files plus Users.txt with `ofstream` (which **overwrites** the file completely). It loops through each vector and writes `serialize()` output. This is called:
- On explicit "Save Data" (Manager menu option 11)
- On Manager logout (Line 700)
- On program exit (Line 548 in `run()`)
- On destructor (Line 520)

### 9.4 Load Mechanism (Lines 984–1154)

`loadData()` is called ONCE in the constructor. Each `loadX()` function:
1. Opens the file with `ifstream` (read-only)
2. Reads line by line with `getline(file, line)`
3. Skips empty lines (`if (line.empty()) continue`)
4. Creates a `stringstream` from the line
5. Extracts fields using `getline(ss, field, '|')` — splits on pipe
6. Converts strings to numbers with `stoi()` (int) or `stod()` (double)
7. Creates object using the 4-parameter file-loading constructor
8. Adds to vector with `emplace_back`

---

## 10. Template Functions

### 10.1 readNumber<T> (Lines 62–78)

**Signature:** `template <typename T> T readNumber(const string &prompt, T minValue, T maxValue)`

**Instantiated as:**
- `readNumber<int>()` — for menu choices, ages, quantities, IDs
- `readNumber<double>()` — for prices, salaries, costs

**How template works:** The compiler generates TWO versions of this function: one where T=int (uses `cin >> int`) and one where T=double (uses `cin >> double`). Same validation logic for both.

### 10.2 findById<T> (Lines 80–87)

**Signature:** `template <typename T> const T *findById(const vector<T> &items, int id)`

```cpp
template <typename T>
const T *findById(const vector<T> &items, int id) {
    auto it = find_if(items.begin(), items.end(), [id](const T &item)
                      { return item.getId() == id; });
    return (it == items.end()) ? nullptr : &(*it);
}
```

**How it works:**
1. Uses `std::find_if` with a **lambda** that captures `id` by value
2. The lambda calls `item.getId()` — this works because ALL classes that use this template have a `getId()` method (inherited from ParkEntity or defined in Ticket/Feedback)
3. If found, returns pointer to the item. If not found, returns `nullptr`

**Instantiated as:**
- `findById<Visitor>(visitors, visitorId)` — Line 795
- `findById<Ride>(rides, rideId)` — Line 802

---

## 11. Exception Handling — Every Try-Catch & Throw

### 11.1 All throw Statements

| # | Exception Type | Message | Where | Line |
|---|---|---|---|---|
| 1 | `runtime_error` | "Add at least one visitor and one ride first." | `bookTicket()` | 790 |
| 2 | `runtime_error` | "Visitor ID not found." | `bookTicket()` | 797 |
| 3 | `runtime_error` | "Ride ID not found." | `bookTicket()` | 804 |
| 4 | `runtime_error` | "Ride is currently under maintenance." | `bookTicket()` | 806 |
| 5 | `invalid_argument` | "Discount must be between 0 and 100." | `applyDiscount()` | 240 |
| 6 | `runtime_error` | "Event is full." | `Event::registerVisitor()` | 285 |
| 7 | `runtime_error` | "Insufficient inventory." | `Inventory::updateQuantity()` | 436 |

### 11.2 All try-catch Blocks

| # | Where | Lines | What It Catches | What It Does |
|---|---|---|---|---|
| 1 | `run()` main loop | 535–558 | `const exception &ex` | Prints error in red, continues loop |
| 2 | `staffPortal()` loop | 602–631 | `const exception &ex` | Prints error in red, continues loop |
| 3 | `managerPortal()` loop | 659–708 | `const exception &ex` | Prints error in red, continues loop |

**Exception flow:** When `bookTicket()` throws `runtime_error("Ride ID not found.")`, it propagates up to the `catch` block in `staffPortal()` (Line 627–631). The error message is printed in red, and the staff menu loop continues — the program does NOT crash.

---

## 12. STL Usage

### 12.1 Vectors (Lines 491–498)

`std::vector` is used as the primary container for ALL data:
```cpp
vector<Visitor> visitors;
vector<Ride> rides;
vector<Ticket> tickets;
vector<Event> events;
vector<Staff> staff;
vector<Feedback> feedbacks;
vector<Inventory> inventory;
vector<User> users;
```

**Operations used:**
- `push_back()` — Line 814 (adding ticket)
- `emplace_back()` — Lines 732, 745, 758, 771, 783, 1012, etc. (constructing in-place)
- `empty()` — Lines 789, 822, 839, etc. (checking if collection has items)
- `begin()/end()` — used with algorithms
- `size()` — Line 406 (calculating average)

### 12.2 Algorithms

| Algorithm | Header | Where Used | Line | Purpose |
|---|---|---|---|---|
| `find_if` | `<algorithm>` | `findById<T>()` | 83 | Searches vector for item with matching ID |
| `sort` | `<algorithm>` | `listTickets()` | 913 | Sorts tickets by price (uses `operator<`) |

### 12.3 Lambda Functions

**Lambda 1 — findById (Line 83–84):**
```cpp
[id](const T &item) { return item.getId() == id; }
```
Captures `id` by value, returns true if item's ID matches. Used inside `std::find_if` within the template function.

---

## Summary — All OOP Concepts at a Glance

| OOP Concept | Where | Key Lines |
|---|---|---|
| **Inheritance** | 5 classes inherit from ParkEntity | 108, 150, 255, 307, 410 |
| **Polymorphism (Runtime)** | Base pointer calls derived display() | 828–833, 845–850, 862–867, 879–884, 896–901 |
| **Polymorphism (Compile-time)** | Templates & operator overloading | 62–87, 227–228, 245–252 |
| **Abstraction** | Pure virtual functions in ParkEntity | 103–104 |
| **Encapsulation** | Private members + public getters | Every class (110–113, 152–155, etc.) |
| **Operator Overloading** | `+`, `<`, `<<` in Ticket | 227, 228, 245–252 |
| **Friend Functions** | applyDiscount, operator<<, calculateAverageRating | 231–232, 237–252, 392, 397–407 |
| **Static Members** | nextId counters in 7 classes | 113, 155, 199, 261, 312, 356, 415 |
| **Virtual Destructor** | ~ParkEntity() | 98 |
| **Composition** | ThemeParkSystem owns all vectors | 491–498 |
| **Aggregation** | Ticket/Feedback store IDs (not objects) | 196–197, 353 |
| **Templates** | readNumber<T>, findById<T> | 62–87 |
| **Exception Handling** | 7 throws, 3 try-catch blocks | 240, 285, 436, 790, 797, 804, 806 |
| **File Handling** | 8 text files, serialize/deserialize | 944–1154 |
| **STL Vectors** | 8 vectors store all data | 491–498 |
| **STL Algorithms** | find_if, sort | 83, 913 |
| **Lambdas** | 1 lambda function | 83 |

---

*End of Complete Documentation*
