# C++ OOP — 30 Scenario-Based Exam Questions (Inheritance Focus)

> Styled after real mid-exam papers. Each question is a full scenario requiring class design, inheritance, implementation, and OOP reasoning.

---

## 🟢 Level 1: Foundation Scenarios (Q1–Q10)

---

### Q1 — Bank Accounts Tracker (Protected Members)

A bank needs to manage normal accounts and savings accounts securely. Design a class `Account` with:
- `balance` (double) as a **protected** member.
- A **static member** `totalAccounts` that tracks how many accounts exist.
- `deposit()` and `withdraw()` methods.

Design a derived class `SavingsAccount : public Account` with:
- `interestRate` (double).
- `applyInterest()` method which directly accesses `balance` to increase it.

**In `main()`:**
- Create 3 `SavingsAccount` objects on the stack.
- Deposit money and apply interest.
- Print the total accounts using the static counter.

**What OOP principle prevents `main()` from accessing `balance` directly, but allows `applyInterest()` to modify it? Explain.**

---

### Q2 — Employee ID Subclasses (Static + Constructor Chaining)

A company assigns auto-incrementing IDs to different types of staff. Implement:
- Class `Employee` (Base) with `name` (string) and `id` (int).
- A `static int nextID` initialized to `5000` outside the class using the **scope resolution operator**.
- Constructor taking `name` and auto-assigning `id = nextID++`.

Implement `Manager : public Employee` with `department` (string).
- The `Manager` constructor takes `name` and `department`. It MUST pass `name` exactly to the `Employee` constructor using an initialization list.

**In `main()`:**
- Create Managers: `"Ali"` ("IT"), `"Sara"` ("HR").
- Display them.

**Expected Output:**
```
Manager: Ali (ID: 5000), Dept: IT
Manager: Sara (ID: 5001), Dept: HR
```

**Exam question:** What would happen if you forget the `Employee(name)` initializer in the `Manager` constructor, assuming `Employee` has no default constructor?

---

### Q3 — Chain of Command (this Pointer + Method Chaining)

Design a `User` class:
- `username` (string), `accessLevel` (int).
- Constructor uses `this->` to resolve parameter shadowing.
- `User& setUsername(string name)` returns `*this`.

Design `Admin : public User` with:
- `Admin& setPrivileges(int level)` returns `*this`.

**In `main()`:**
```cpp
Admin a("Sarim", 1);
a.setUsername("SuperBoss").setPrivileges(5).display();
```

**Why does `setPrivileges` chained after `setUsername` cause a compiler error? (Hint: check the return type of `setUsername`). How would you fix the design?**

---

### Q4 — Polymorphic Zoo (Base Object Pointers)

A zoo stores animals dynamically. Implement:
- Base Class `Animal` with `virtual string type() { return "Animal"; }`.
- Derived Class `Tiger` extending `Animal` with `string type() { return "Tiger"; }`.

- In `main()`, create **3 Animal pointers pointing to Tiger objects on the heap**.
- Access and print each animal's type using the **arrow operator (`->`)**.
- Properly **deallocate** all memory.

**Trick question:** What happens if `Animal` lacks a `virtual` destructor and you `delete` an `Animal*` pointing to a `Tiger`?

---

### Q5 — Weapon Storage (Composition vs Inheritance Logic)

A game app records a Warrior's equipment. 
Design A (Composition): `Warrior` has a `Weapon currentWeapon;`.
Design B (Inheritance): `Warrior` inherits from `Weapon`.

**Why is Design A correct and Design B conceptually incorrect? Explain "IS-A" vs "HAS-A" relationships in OOP. What would change in memory layout if `Weapon` were an inherited base class instead of a composition member?**

---

### Q6 — Corporate Hierarchy (Array of Base Pointers)

An HR system manages employees dynamically. Implement:
- Base `Employee` with `virtual void show()`.
- Derived `Programmer` and `Designer`.
- In `main()`, create an **array of 5 Employee pointers** (`Employee* team[5]`).
- Dynamically allocate a mix of Programmers and Designers to the array.
- Loop through and display all.
- **Deallocate properly**.

**Draw the memory diagram** showing the stack array of base pointers pointing to the inherited heap objects.

---

### Q7 — Derived Class Shallow Copy Bug 

A game engine logs player names. Implement:
- Class `Entity` with `char* name` (dynamic array). Provide a deep copy constructor for `Entity`.
- Class `Player : public Entity` with `int score`.
- **Do NOT write a copy constructor for `Player`** (use compiler default).

**In `main()`:**
```cpp
Player p1("Hero", 100);
// ... fill with values ...
Player backup = p1;  // Shallow copy implicitly created for Player
```

- Modify `backup`'s name.
- Print `p1`'s name.

**Questions:**
1. Why did `p1`'s name also change even though `Entity` has a deep copy constructor? (Hint: Does the default `Player` copy constructor call the `Entity` copy constructor properly?)
2. Will the program crash at exit? Why?

---

### Q8 — Deep Copy in Derived Classes

Fix the `Player` class from Q7. Implement a proper Rule of Three for `Player`:
- Write a **deep copy constructor** that correctly invokes `Entity(const Entity&)` in its initializer list.
- Write a **deep copy assignment operator** (`operator=`).
- Include the **self-assignment guard** in `operator=`.

**In `main()`:**
```cpp
Player a("Ali", 5);
Player b = a;       // Deep copy constructor
Player c("Sara", 3);
c = a;              // Deep copy assignment
```

**Prove independence** by modifying `a`'s name and showing `b` and `c` are unchanged.

---

### Q9 — The Assembly Line (Base, Child, and Composition Order)

Design a system where:
- Class `Engine` prints `"Engine built"` / `"Engine destroyed"`.
- Class `Vehicle` (Base) prints `"Vehicle built"` / `"Vehicle destroyed"`.
- Class `Car : public Vehicle` has an `Engine eng;` as a member (composition).
- `Car` prints `"Car built"` / `"Car destroyed"` in its constructor/destructor body.

**In `main()`:** Create one `Car` object inside a block `{ }` and let it go out of scope.

**Trace the exact output.** Then answer: In what exact order do constructors run when mixing inheritance and composition?

---

### Q10 — Base vs Derived Scope Resolution (Name Hiding)

Given this code:
```cpp
class Base {
public:
    int score = 100;
    void show() { cout << "Base"; }
};

class Game : public Base {
public:
    int score = 50;
    void show() {
        int score = 10;
        // Print all three scores from here
    }
};
```

**Write the three `cout` statements inside `Game::show()` that print:**
```
Local: 10
Derived: 50
Base: 100
```

**Which operator is used for the base member? Does `Game::show` override `Base::show`, or does it just hide it?**

---

## 🟡 Level 2: Multi-Concept Scenarios (Q11–Q20)

---

### Q11 — Framework GUI (Aggregation + Base Pointers)

A UI framework doesn't own its drawn windows. Design:
- Class `Widget` (Base).
- Class `Button : public Widget` with `label`.
- Class `Window` with `Widget** elements` (array of base pointers), `int capacity`, `int count`.
- `Window` constructor allocates the pointer array.
- `addElement(Widget* w)` — adds a pointer (does NOT create a new widget).
- `~Window()` — frees the **pointer array only**, NOT the Widget objects.

**In `main()`:**
```cpp
Button* b1 = new Button("Submit");
Button* b2 = new Button("Cancel");
Window w("Dialog", 10);
w.addElement(b1);
w.addElement(b2);
// Window destroyed — buttons still alive
```

**Why must the Window NOT delete the Widget objects? What would happen if it did and main() also tries to use `b1` afterward?**

---

### Q12 — E-Commerce Cart (Object Assignment & Slicing)

An e-commerce platform needs a cart that owns its items. Design:
- Class `Product` with `name` (string), `price` (double).
- Class `DigitalProduct : public Product` with `downloadLink`.

**In `main()`:**
```cpp
DigitalProduct d1("E-Book", 19.99, "link.com/ebook");
Product p1 = d1;     // Assignment slicing
```

**What would go wrong here? Where did the `downloadLink` go? Draw the memory diagram of `d1` and `p1`.**

---

### Q13 — Airline Hierarchy (Static + Inheritance + Array of Pointers)

An airline reservation system. Design:
- Class `Person` with `name` and `static int totalPeople`.
- Class `Passenger : public Person` with `seatNumber`.
- The `Person` constructor increments the static counter.
- `PrintPassenger()` uses `this->` to print seat info.

**In `main()`:**
- Create `Person* manifest[4]` — array of 4 base pointers, dynamically allocating `Passenger` objects to them.
- Delete passenger at index 1. 

**What happens to `totalPeople` if you forget a `virtual` destructor on `Person`?**

---

### Q14 — Course Roster (Shallow copy of Base Pointers)

Design:
- Class `Student` with `name`, `gpa`.
- Class `GradStudent : public Student` with `thesisTopic`.
- Class `Course` with `Student** enrolled` (array of base pointers — **aggregation**), `int maxStudents`.

Now answer:
```cpp
Course oop("OOP", 30);
oop.enroll(s1);
oop.enroll(s2);

Course backup = oop;  // Default copy
```

1. **Is this a shallow or deep copy of the student pointers?**
2. **Draw the memory diagram** showing both `oop` and `backup` pointing to the exact same Student objects.
3. **When would you want shallow vs deep here?** (Hint: think about whether backup should reflect real-time GPA changes.)

---

### Q15 — Hiding Shared Policies (Static + Scope Resolution)

Design a corporate structure:
- Class `Company` with `static void shiftHours() { cout << "9 to 5"; }`.
- Class `Branch : public Company` with `static void shiftHours() { cout << "10 to 6"; }`.

**In `main()`:**
Call both methods WITHOUT instantiating any objects.

**Explain why static methods cannot be polymorphic (virtual). If a pointer `Company* c = new Branch();` calls `c->shiftHours()`, which one runs?**

---

### Q16 — Digital RPG Arena (Full Scenario — Inheritance Edition)

Develop a program organizing a battle where two characters compete.
**Class `Character` (Base):**
- `hp` (int), `name` (string).
- `virtual void attack(Character& target) = 0;` (Pure virtual if known, otherwise just generic output).

**Class `Warrior : public Character`:**
- Adds `int swordDamage`.
- `attack()` reduces target's hp by `swordDamage`.

**Class `Mage : public Character`:**
- Adds `int magicDamage`.
- `attack()` reduces target's hp by `magicDamage` and increases own hp by 5.

**In `main()`:**
- Create a Warrior and a Mage.
- Simulate 3 rounds of attacking each other. Display remaining HP.

**Full implementation required.**

---

### Q17 — Folder Hierarchy (Array of Base Pointers + Deep Copy + Destructor)

A file system tracks nodes. Design:
- Class `Node` with `string name`.
- Class `File : public Node` with `int size`.
- Class `Folder : public Node` with `Node** contents` (fully dynamic array of generic Node pointers), `int count`.
- **Destructor of Folder** — must cascade and `delete` every Node, then delete the pointer array.

**In `main()`:**
```cpp
Folder root("Root");
root.addNode(new File("doc1.txt", 500));
root.addNode(new File("doc2.txt", 300));

Folder backup = root;  // Deep copy recursively creating new files/folders!
```

**Write the destructor. Common bug: what happens if you only `delete[] contents` without the loop?**

---

### Q18 — Organizational Chart (Recursive Aggregation + this Pointer)

Design:
- Class `Employee` with `name`, `salary`.
- Class `Manager : public Employee` with `Employee* reportsTo` (aggregation — points to another Employee, default `nullptr`).
- `promoteUnder(Manager& mgr)` — sets `this->reportsTo = &mgr`. Uses `this` to ensure an employee can't restrict themselves.
- `displayChain()` — prints `this` employee's name, then recursively prints up the chain.

**In `main()`:**
```cpp
Manager* ceo = new Manager("Boss", 200000);
Manager* dev = new Manager("Dev", 60000);

dev->promoteUnder(*ceo);
dev->displayChain();
```
**Expected output chain:** `Dev → Boss`. 

---

### Q19 — Graphic Engine (2D Dynamic Memory + Slicing/Leak)

Design:
- Class `Canvas` with `int** pixels` (2D dynamic array), `width`, `height`. Complete Rule of Three implemented correctly.
- Class `LayeredCanvas : public Canvas` adds a `char* layerName` (dynamic string).

**Identify the memory leak AND the slicing issue in this buggy `operator=`:**
```cpp
LayeredCanvas& operator=(const LayeredCanvas& other) {
    if (this == &other) return *this;
    
    // FORGOT to call base assignment operator! 
    // FORGOT to free old layerName!

    layerName = new char[strlen(other.layerName) + 1];
    strcpy(layerName, other.layerName);
    
    return *this;
}
```

**How many bytes are leaked if the old canvas was 100×100 of `int`? What happens to the base class `pixels` array?**

---

### Q20 — Game Inventory (Composition + Overriding + Base Initialization)

Design:
- Class `Weapon` with `name` (char* — dynamic C-string). Rule of Three implemented.
- Class `Unit` with `string type`.
- Class `Soldier : public Unit` has `Weapon weapon;` (composition).
- `Soldier` copy constructor should trigger both Base initialization and Weapon's deep copy automatically.

**In `main()`:**
```cpp
Soldier s1("INFANTRY", Weapon("Sword"));
Soldier s2 = s1;  
```

**Prove that modifying `s1`'s weapon name does NOT affect `s2`. Trace the constructor steps triggered exactly when `s2` is created.**

---

## 🔴 Level 3: Exam-Grade Full Scenarios (Q21–Q30)

---

### Q21 — Cyberpunk Corporation System (Full Implementation)

In a futuristic megacorp, employees manage assets. Design and implement:

**Class `Asset`:**
- `id` (int), `value` (double). Protected members.

**Class `Cyberware : public Asset`:**
- `implants` (string array). Constructor uses member initialization list.

**Class `Corporation`:**
- `corpName` (string).
- `Asset** vault` (aggregation — dynamic array of pointers to external Assets).
- `int count`.

**Implement:**
1. Corporation constructor allocates `Asset*` array.
2. `storeAsset(Asset* a)` — adds polymorphism by accepting any inherited Asset.
3. Destructor frees the pointer array only (aggregation — does NOT delete Assets).

**In `main()`:** Create Cyberware, store in Corporation, let Corp destruct. Prove Cyberware is still alive.

---

### Q22 — Social Media Platform (Deep Copying a Network)

Design a social media backend:

**Class `Content` (Base):**
- `id` (int). Full Rule of Three.

**Class `Post : public Content`:**
- `body` (char* — dynamic).
- Deep copy constructor explicitly calling Base copy constructor.

**Class `Feed`:**
- `Content** items` (array of pointers, heap).
- **Deep copy constructor** — deep copies every Content object to ensure independence.
- Destructor deletes all inherited Post items and the array.

**In `main()`:**
```cpp
Feed f1(10);
f1.addPost(new Post("Hello World!"));

Feed f2 = f1;  // Deep copy recursively creates new posts
```

**Draw the complete memory diagram after the deep copy. Label what's shared and what's independent.**

---

### Q23 — Advanced Hospital Directory (Composition + Aggregation + Inheritance)

Design:
- Class `Address` (composition candidate) — `city`, `street`.
- Class `Person` (Base).
- Class `Doctor : public Person` — `specialization`, `Address address` (composition — doctor OWNS their address).
- Class `Hospital` — `Address hqAddress` (composition), `Person** staff` (aggregation — array of pointers to external staff including Doctors).

**Implement:**
- Hospital doesn't own doctors — they switch hospitals.
- Write deep copy constructor for Hospital: deep copies the Address, but **shallow copies** the staff pointers (aggregation).
- Destructor deletes pointer array, NOT the people.

**Explain: Why is Address composition but Staff is aggregation? What real-world relationship does each represent?**

---

### Q24 — Online Examination Network (Rule of Three Chaining)

Design:
- Class `Module` with `char* title` (dynamic). Rule of Three.
- Class `Exam : public Module` with `int fullMarks`.
- Exam MUST implement its own Rule of Three, explicitly chaining `Module::operator=` inside `Exam::operator=`.

**In `main()`:**
```cpp
Exam midterm("OOP Mid", 100);
Exam backup("", 0);
backup = midterm;  // Deep copy assignment chain
```

**List exactly which operators/copy constructors execute in sequence when `backup = midterm` runs.**

---

### Q25 — Automated Factory (Full Destructor Chain Trace)

```cpp
class Machine {
    static int count;
public:
    Machine()  { count++; cout << "M+" << count << " "; }
    ~Machine() { cout << "M-" << count << " "; count--; }
    static int getCount() { return count; }
};
int Machine::count = 0;

class Core {
    int* power;
public:
    Core(int p) { power = new int(p); cout << "C+ "; }
    Core(const Core& o) { power = new int(*o.power); cout << "CC "; }
    ~Core() { cout << "C-(" << *power << ") "; delete power; }
};

class Robot : public Machine {
    Core mainCore;    // Composition
    Core* backup;     // Aggregation
public:
    Robot(int p, Core* b) : Machine(), mainCore(p), backup(b) { cout << "R+ "; }
    ~Robot() { cout << "R- "; }
};

int main() {
    Core* extra = new Core(500);
    cout << endl;
    {
        Robot r(1000, extra);
        cout << endl;
        cout << "Machines: " << Machine::getCount() << endl;
    }
    cout << endl << "After robot destroyed - Machines: " << Machine::getCount() << endl;
    delete extra;
    return 0;
}
```

**Trace the COMPLETE output line by line. Explain the exact order of construction and destruction regarding the Base class and Composition member.**

---

### Q26 — Cloud Database Records (2-Level Hierarchy Deep Copy)

Design:
- Class `RowNode` with `char* primaryKey` (dynamic). Full Rule of Three.
- Class `Table : public RowNode` with `RowNode** connectedRows` (dynamic array of child references).
- Deep copy constructor must deep copy the array, and manually invoke the Base copy constructor for the PK.

**In `main()`:**
```cpp
Table t1("USER_ID");
Table t2 = t1;  // Two-level deep copy
```

**How many `new` calls happen during the copy if `t1` has 3 items in its `connectedRows`?**

---

### Q27 — Ride-Sharing Fleet (Pointer Variants + Inheritance)

Design a ride-sharing system:

**Class `User` (Base):** `name`, `static int activeUsers`.
**Class `Rider : public User`:** dynamic `char* location`. Generates deep copy implementations.
**Class `Driver : public User`:** `bool isAvailable`.

**Class `Ride`:**
- `Rider* rider`, `Driver* driver` (both Aggregation).
- Uses `this` pointer in `confirmRide()` to print the Ride object's address.

**In `main()`:**
- Create `Rider*` and `Driver*` arrays.
- Create Ride objects matching them up.
- Print static counters for Users.
- Properly clean up ALL memory without crashing.

**Write the clean up sequence. Can you delete a Rider before deleting the Ride that references them?**

---

### Q28 — Smart University System (Composition + Base Arrays + Shared Pointers)

Design:
- **Class `Schedule`** (Base, value type) — `int hours`.
- **Class `Timetable : public Schedule`** — `TimeSlot slot;` (composition).
- **Class `Course`** — Contains `Timetable*` array (Composition - owned) and `User**` student list (Aggregation - borrowed).

**Implement deep copy constructor for Course:**
Must deep copy Timetable array (owns it), but shallow copy User array (borrows them).

**Explain: For the copied Course, which parts are independent copies and which are shared with the original?**

---

### Q29 — Multiplayer Clan System (Grand Combo + Early Binding)

Design a server managing clans:

**Class `Character` (Base):**
- `char* tag` (dynamic C-string). Full Rule of Three.
- `virtual void showStatus() { cout << "Character: " << tag; }`

**Class `Player : public Character`:**
- `int rank`. Overrides `showStatus()`.

**Class `ClanRoom`:**
- `string clanName`, `Character** members` (array of BASE pointers — **aggregation**).
- `ClanRoom(const ClanRoom& other)` — **shallow copies** member pointers.

**In `main()`:**
```cpp
Player* p1 = new Player("Shadow", 10);
ClanRoom lobby("Elite", 5);
lobby.addMember(p1);

ClanRoom backup = lobby;  // Shallow copy

backup.members[0]->showStatus();  // Early binding or Late binding?
```

**Trace through: After `delete p1`, what happens if `backup.members[0]->showStatus()` is called? (Dangling pointer!) How would you prevent this if the room was Composition?**

---

### Q30 — The Supreme AI Frame (The Ultimate Inheritance Test)

Design a complete system combining every concept:

**Class `Module` (Base):**
- `char* coreID` (dynamic C-string).
- **Rule of Three** implemented explicitly.

**Class `AI_Unit : public Module`:**
- `int powerLevel`, `static int activeUnits`.
- Constructor uses `this->`, chains `coreID` down to `Module::Module(const char*)`.
- Copy assignment operator chains to `Module::operator=`.

**Class `Factory`:**
- `AI_Unit** deployedUnits` (aggregation — array of base/derived pointers).
- `Component* inventory` (composition — dynamic array).

**Implement:**
1. Factory constructor allocating both arrays.
2. Formatted output iterating through pointers.
3. Factory deep copy.
4. Clean destruction ensuring `deployedUnits` (the objects) survive, but the array container and `inventory` objects die.

**In `main()`:** Populate the Factory, copy it, delete original, and display static counts and remaining units.

**This final question acts as an absolute verification of Composition, Aggregation, Shallow/Deep Copying Base/Derived classes, Constructor Chains, and Static Memory.**

---

## Scoring Guide

| Score | Verdict |
|-------|---------|
| 25–30 fully correct | You're exam-ready. Walk in with confidence. |
| 18–24 | Solid but revisit the topics you missed. |
| 10–17 | Re-study the Notes, focus on memory layout. |
| < 10 | Start from fundamentals again. |

---

> **How to practice:** Write each answer **on paper first** (no IDE). That's what the exam will be. Time yourself: ~15 mins for Level 1, ~25 mins for Level 2, ~35 mins for Level 3.
