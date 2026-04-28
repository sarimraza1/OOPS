# 🎯 OOP Midterm Study Guide — Lab 1 to Lab 7

> Based on a complete analysis of every `.cpp` file across all 7 labs in your repo.

---

## 📘 LAB 1 — C++ Basics & Functions

**Core Theme:** Procedural programming fundamentals — no classes yet, pure logic building.

### Concepts Covered:

| Concept | Description | File |
|---|---|---|
| **Functions** | Defining and calling custom functions | `1.cpp`, `2.cpp`, `5.cpp` |
| **Return values** | Functions returning `int`, using conditionals on returned value | `1.cpp` |
| **Loops** | `for` loops for iteration | `2.cpp`, `4.cpp`, `6.cpp` |
| **if / else-if / else** | Multi-branch conditional logic | `2.cpp`, `7.cpp` |
| **switch-case** | Menu-driven programs using `switch` | `3.cpp` |
| **Arrays** | Declaring and traversing arrays | `4.cpp` |
| **Recursion** | Factorial using recursive function calls | `5.cpp` |
| **Arithmetic operations** | Slab-based billing, grade calculation | `2.cpp`, `7.cpp` |
| **Even/Odd checking** | Using modulus `%` operator | `4.cpp`, `6.cpp` |
| **Range-based logic** | Printing even numbers in a range, skipping odds | `6.cpp` |

### Key Programs:
- **Prime Number Check** — Function returning 0 or 1
- **Grade Calculator** — for loop + average + if-else ladder
- **Calculator** — switch-case with char operator
- **Even/Odd Counter** — Array + loop
- **Factorial** — Recursion
- **Electricity Bill** — Slab-wise billing using nested if-else

---

## 📘 LAB 1-2 (Mixed Lab) — Structs, Pointers & Dynamic Memory

**Core Theme:** Bridging from procedural to OOP using structs, and introducing pointers/dynamic memory.

### Concepts Covered:

| Concept | Description | File |
|---|---|---|
| **Structs** | Defining custom data types with `struct` | `1.cpp`, `2.cpp` |
| **Struct arrays** | Array of struct objects | `1.cpp`, `2.cpp` |
| **Passing structs to functions** | Pass-by-value | `1.cpp` |
| **String input with `getline`** | Reading multi-word strings | `1.cpp` |
| **CRUD operations** | Add, Display, Update, Remove using struct arrays | `2.cpp` |
| **Pointers** | `int *`, pointer arithmetic, dereferencing with `*` | `3.cpp`, `4.cpp` |
| **`new` and `delete`** | Dynamic memory allocation/deallocation | `3.cpp`, `6.cpp` |
| **`new[]` and `delete[]`** | Dynamic arrays | `3.cpp`, `5.cpp`, `6.cpp` |
| **Double pointers `**`** | 2D dynamic arrays — pointer to pointer | `5.cpp` |
| **Dynamic resizing** | Growing an array by doubling its capacity | `6.cpp` |
| **Matrix operations** | Addition, subtraction, multiplication of dynamically allocated matrices | `5.cpp` |
| **Pass by pointer** | Using `&` to get address and `*` to dereference | `4.cpp` |

### Key Programs:
- **Library Management System** — Struct, struct arrays, getline, CRUD
- **Inventory System** — Structs with functions, remove by shifting
- **Dynamic Array Allocation** — `new int[n]`, `delete[]`
- **Pointer Calculator** — Pass addresses to math functions
- **Dynamic Matrix Operations** — 2D `new` arrays, add/sub/mul
- **Self-Resizing Dynamic Array** — Doubling, shrinking, `delete[]`

---

## 📘 LAB 2 — Classes, Encapsulation, Getters & Setters

**Core Theme:** Introducing OOP with `class`, `public`/`private` access, member functions.

### Concepts Covered:

| Concept | Description | File |
|---|---|---|
| **Classes** | Defining a `class` with data members and functions | All files |
| **Objects** | Creating instances of a class | All files |
| **Access specifiers** | `public` vs `private` | `1.cpp`, `2.cpp`, `3.cpp`, `5.cpp` |
| **Encapsulation** | Hiding data; only accessible through public methods | `1.cpp`, `2.cpp` |
| **Setters** | Functions that set private member values | `1.cpp`, `2.cpp`, `3.cpp` |
| **Getters** | Functions that return private member values | `1.cpp`, `2.cpp`, `3.cpp` |
| **Member functions** | Behavior methods like `write()`, `refill()`, `drinkWater()` | `1.cpp`, `3.cpp` |
| **In-class initialization** | Default value for member `double pi = 3.14159` | `2.cpp` |
| **Constructor (basic)** | `StationeryShop()` initializing count to 0 | `4.cpp` |
| **Arrays inside classes** | `string items[100]`, `double prices[100]` | `4.cpp` |
| **`do-while` loop** | Used in receipt generation | `4.cpp` |
| **Boolean logic** | Writing only if ink exists, refilling only if refillable | `1.cpp` |

### Key Programs:
- **Board Marker** — Setters/Getters/Behavior methods; `write()`, `refill()`
- **Circle** — Area, diameter, circumference via getters
- **Water Bottle** — Unit conversion ml↔L inside setters
- **Stationery Shop** — Array-based inventory + receipt generation
- **Employee Salary** — Tax calculation with update method

---

## 📘 LAB 3 — Constructors, Destructors & `this` Pointer

**Core Theme:** Object lifecycle management and method chaining.

### Concepts Covered:

| Concept | Description | File |
|---|---|---|
| **Default Constructor** | No-arg constructor providing defaults | `1.cpp`, `2.cpp`, `5.cpp` |
| **Parameterized Constructor** | Constructor that takes arguments | `1.cpp`, `2.cpp`, `3.cpp`, `4.cpp`, `5.cpp` |
| **Copy Constructor** | `Book(const Book &b)` — copying one object into another | `1.cpp`, `5.cpp` |
| **Default Arguments** | Function/constructor parameters with default values | `1.cpp`, `5.cpp` |
| **Destructor** | `~SmartDevice()` — runs when object is destroyed | `3.cpp`, indirectly `6.cpp` |
| **Dynamic objects** | `new ClassName(...)` and `delete` — triggering destructor explicitly | `3.cpp` |
| **`this` pointer** | Used to resolve name conflict between parameter and member | `4.cpp` |
| **Method chaining** | Returning `*this` to allow `.method1().method2()` | `4.cpp` |
| **Scope-based destruction** | Objects in `{}` block destroyed at closing brace | (concept from `Lab4-5/6.cpp`) |

### Key Programs:
- **Book** — All 3 constructor types + default args in one class
- **WeekDays** — Default + parameterized, circular day logic
- **SmartDevice** — Parameterized constructor + destructor message + `new`/`delete`
- **CricketPlayer** — `this->` pointer + method chaining (`return *this`)
- **FootballPlayer** — All 3 constructor types + default args in one class

---

## 📘 LAB 4-5 — Static Members & Class Composition

**Core Theme:** Class-level shared data using `static`, and embedding objects inside objects.

### Concepts Covered:

| Concept | Description | File |
|---|---|---|
| **`static` data members** | Shared across ALL objects of a class | `3.cpp`, `6.cpp`, `7.cpp`, `8.cpp`, `9.cpp`, `10.cpp` |
| **`static` member functions** | Called with `ClassName::functionName()` | `3.cpp`, `6.cpp`, `9.cpp`, `10.cpp` |
| **Static member definition** | Must define outside: `float BankAccount::interestRate = 3.0;` | `3.cpp`, `7.cpp`, etc. |
| **`const` member functions** | `void show() const` — cannot modify the object | `1.cpp`, `7.cpp`, `9.cpp` |
| **Class composition** | One class has an object of another class as a member | `4.cpp`, `5.cpp`, `8.cpp`, `9.cpp`, `10.cpp` |
| **Nested access** | `c.eng.horsepower` — accessing composed object's member | `4.cpp`, `5.cpp` |
| **Initializer list** | `Player(...) : weapon(wName, dmg)` — initialize composed object | `8.cpp` |
| **Object arrays** | Array of class objects | `2.cpp`, `8.cpp`, `9.cpp`, `10.cpp` |
| **Pointer to class object** | `Project *project` member, `arr[i].project->projectTitle` | `9.cpp`, `10.cpp` |
| **Constructor auto-increment** | `totalPlayers++` in constructor, `--` in destructor | `6.cpp`, `8.cpp` |

### Key Programs:
- **Car** — `const` member function
- **Book array** — Array of objects with public data
- **BankAccount** — `static` rate shared by all objects
- **Car + Engine** — Composition (Engine inside Car)
- **Student + Department** — Composition with array of composite objects
- **Player** — `static int totalPlayers`, destructor decrements it
- **Account** — `static` members + constructor + `const` show
- **Player + Weapon** — Composition + static counter + initializer list + `new[]`/`delete[]`
- **Employee + Project** — Composition via pointer + `static` tax rate
- **Account + Branch** — Composition via pointer + `static` bank info

---

## 📘 LAB 6 — Inheritance (All Types) — DETAILED NOTES

**Core Idea:** Inheritance lets a class (child/derived) automatically get all the members of another class (parent/base). You write the shared stuff once in the base, then specialize in the child.

---

### 🔑 What IS Inheritance?

Inheritance = **is-a** relationship.
- `FictionBook` *is a* `Book` ✅
- `Car` *is a* `Vehicle` ✅
- `GraduateStudent` *is a* `Student` AND *is a* `Teacher` ✅

---

### 🔑 Basic Syntax

```cpp
class Animal {
public:
    string name;
    void eat() { cout << "Eating..." << endl; }
};

// Dog inherits from Animal
class Dog : public Animal {
public:
    void bark() { cout << "Woof!" << endl; }
};

int main() {
    Dog d;
    d.name = "Rex";   // inherited from Animal
    d.eat();          // inherited from Animal
    d.bark();         // Dog's own method
}
```

**Access rule with `public` inheritance:**
- `public` members of base → still `public` in child
- `protected` members of base → still `protected` in child
- `private` members of base → **NOT accessible** in child (they exist but are hidden)

---

### 🔑 Access Specifiers: public / protected / private

| Specifier | Accessible inside class? | Accessible in derived class? | Accessible from main()? |
|---|---|---|---|
| `public` | ✅ | ✅ | ✅ |
| `protected` | ✅ | ✅ | ❌ |
| `private` | ✅ | ❌ | ❌ |

**Use `protected` when** you want child classes to be able to read/write a member, but the outside world cannot.

---

### 🔑 Calling the Base Constructor

The child constructor **must** pass arguments to the base constructor using the **initializer list**:

```cpp
class Book {
public:
    string title, author;
    Book(string t, string a) { title = t; author = a; }
};

class FictionBook : public Book {
public:
    string genre;
    // ': Book(t, a)' calls the base constructor
    FictionBook(string t, string a, string g) : Book(t, a) {
        genre = g;
    }
};
```

**Rule:** Base constructor is ALWAYS called FIRST, then child constructor body runs.

---

### 🔑 Constructor & Destructor Order

- When an object is created: **Base constructor → Child constructor**
- When an object is destroyed: **Child destructor → Base destructor** (reverse!)

```cpp
// For 3-level: Vehicle → Car → ElectricCar
// Object creation: Vehicle() → Car() → ElectricCar()
// Object destruction: ~ElectricCar() → ~Car() → ~Vehicle()
```

---

### 🔑 Function Overriding (Re-defining a parent function)

If a child defines a function with **the same name and same parameters** as the parent, it *overrides* it.

```cpp
class Shape {
public:
    void draw() { cout << "Drawing shape" << endl; }
};

class Circle : public Shape {
public:
    void draw() { cout << "Drawing circle" << endl; }  // overrides Shape::draw()
};

int main() {
    Circle c;
    c.draw();  // prints "Drawing circle" — child's version is used
}
```

---

### 🔑 Scope Resolution: Calling the Parent's Version

Use `Base::functionName()` inside the child to call the parent's version:

```cpp
class FictionBook : public Book {
public:
    void display() {
        Book::display();    // call parent's version first
        cout << "Genre: " << genre << endl;  // then add child data
    }
};
```

This pattern (call parent, then add child data) is seen in EVERY lab file!

---

### 🔑 Type 1 — Single Inheritance (1 parent → 1 child)

```
Book  →  FictionBook
```

```cpp
class Book { ... };
class FictionBook : public Book { ... };
```

**From Lab6/1.cpp:** `FictionBook` inherits `title, author, publisher` from `Book`, then adds `genre, protagonist`.

---

### 🔑 Type 2 — Hierarchical Inheritance (1 parent → many children)

```
Character → Enemy
          → Player
```

```cpp
class Character { ... };
class Enemy : public Character { ... };
class Player : public Character { ... };
```

**From Lab6/2.cpp:** Both `Enemy` and `Player` share the same parent `Character` (same health, damage).

---

### 🔑 Type 3 — Multi-level Inheritance (chain: A → B → C)

```
Character → Player → Wizard
```

```cpp
class Character { ... };
class Player : public Character { ... };
class Wizard : public Player { ... };  // Wizard gets BOTH Character AND Player members
```

**Key:** `Wizard` objects have access to members from ALL three levels.
**Constructor chain:** `Wizard(args) : Player(args)` → Player's constructor calls `Character(args)` automatically.

---

### 🔑 Type 4 — Multiple Inheritance (2+ parents → 1 child)

```
Position + Health → Character
```

```cpp
class Position { public: int x, y, z; void showPosition(); };
class Health   { public: int hp; void showHealth(); };
class Character : public Position, public Health { ... };
```

**From Lab6/3.cpp:** `Character` gets `x, y, z, showPosition()` from `Position` AND `hp, showHealth()` from `Health`.

**Ambiguity problem:** If both parent classes have a member with the same name, you must qualify which one:

```cpp
// if both Position and Health had a member int 'id'
character.Position::id = 5;
character.Health::id = 10;
```

---

### 🔑 Type 5 — Diamond Problem

```
     Person
    /      \
 Student  Teacher
    \      /
  GraduateStudent
```

`GraduateStudent` inherits from both `Student` and `Teacher`. Both inherit from `Person`.
**Problem:** Two copies of `Person` exist inside `GraduateStudent`. Accessing `name` is ambiguous!

```cpp
// Lab6/4.cpp solution: explicitly qualify
cout << Student::name << endl;  // which copy of name?
```

This compiles but is messy. The REAL fix is **virtual inheritance**.

---

### 🔑 Type 6 — Virtual Inheritance (Diamond Fix)

Add `virtual` keyword when inheriting from the common base:

```cpp
class Person { public: string name; };

class Student : virtual public Person { ... };   // <-- virtual
class Teacher : virtual public Person { ... };   // <-- virtual

class GraduateStudent : public Student, public Teacher {
    // Now there is only ONE copy of Person
};
```

**From Lab6/6.cpp:** `Smartphone : virtual public Device` and `Tablet : virtual public Device`, so `HybridDevice` gets exactly one `Device`.

**CRITICAL RULE:** When virtual inheritance is used, the **most derived class** (here `HybridDevice`) must directly call the virtual base constructor:

```cpp
HybridDevice(string b, string m, int s, bool st)
    : Device(b, m),          // <-- most derived must init virtual base
      Smartphone(b, m, s),
      Tablet(b, m, st) { }
```

---

### 🔑 Concepts Table

| Concept | Syntax / Rule | Lab File |
|---|---|---|
| Single Inheritance | `class Child : public Parent` | `1.cpp` |
| Hierarchical | Same parent, multiple children | `2.cpp`, `4.cpp` |
| Multi-level | `A→B→C`, chain of constructors | `2.cpp`, `5.cpp` |
| Multiple | `class C : public A, public B` | `3.cpp`, `4.cpp` |
| Diamond Problem | Two parents share a grandparent | `4.cpp`, `6.cpp` |
| Virtual Inheritance | `class B : virtual public A` | `6.cpp` |
| Base Constructor Call | `: Base(args)` in initializer list | All files |
| Function Overriding | Same name + same params in child | All files |
| Scope Resolution | `Base::method()` from child | All files |
| protected members | Visible in child, hidden outside | conceptual |

---


## 📘 LAB 7 — Applied Inheritance + Overriding + Overloading — DETAILED NOTES

**Core Idea:** Apply inheritance in real‑world systems. Each child class *specializes* the parent's behavior using **method overriding**. Also introduces **function overloading** (same function name, different parameters).

---

### 🔑 Method Overriding (recap + depth)

Overriding = child defines a method with **identical name + identical parameters** as parent.

```cpp
class Account {
public:
    void withdraw(float amount) {
        balance -= amount;
        cout << "Withdrawn: " << amount << endl;
    }
};

class SavingsAccount : public Account {
public:
    float minimumBalance;
    void withdraw(float amount) {    // OVERRIDE
        if (balance - amount < minimumBalance)
            cout << "Cannot withdraw. Minimum balance must be maintained." << endl;
        else {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
    }
};
```

**Lab7/1.cpp** has 3 account types each overriding `withdraw()`, `calculateInterest()`, and `printStatement()`.

---

### 🔑 Calling Parent's Version Inside Override

Pattern: call `Base::method()` first, then add the child-specific part.

```cpp
// SavingsAccount::printStatement() calls Account::printStatement() first
void printStatement() {
    Account::printStatement();               // base info
    cout << "Interest Rate: " << interestRate << "%" << endl;  // extra info
    cout << "Minimum Balance: " << minimumBalance << endl;
}
```

This avoids repeating code. You DON'T re-print account number, holder name etc. — the base handles it.

---

### 🔑 Function Overloading (NOT the same as overriding!)

**Overloading** = two or more functions with the **same name** but **different parameter lists** in the **same scope**.

```cpp
// From Lab7/5.cpp — two search() functions
void search(Book arr[], int size, string title) {
    // search by title
}

void search(Book arr[], int size, string author, bool byAuthor) {
    // search by author (extra bool param makes it different)
}

// Compiler decides which to call based on arguments:
search(books, 2, "1984");              // calls version 1 (by title)
search(books, 2, "Paulo Coelho", true); // calls version 2 (by author)
```

---

### 🔑 Overloading vs Overriding — KEY TABLE

| Feature | **Overloading** | **Overriding** |
|---|---|---|
| Location | Same class (or same scope) | Parent → Child class |
| Function name | Same | Same |
| Parameters | **Different** | **Identical** |
| Return type | Can differ | Usually same |
| Resolved at | Compile time | Runtime (with `virtual`) |
| Example | `search(arr, n, title)` vs `search(arr, n, author, true)` | `withdraw()` in each account type |

---

### 🔑 Behavioral Specialization per Child

Each child re-defines the same method differently:

| Class | `withdraw()` behavior |
|---|---|
| `Account` (base) | Simple: deduct if balance >= amount |
| `SavingsAccount` | Must maintain minimum balance |
| `CheckingAccount` | Can overdraft up to `overdraftLimit` |
| `FixedDepositAccount` | Cannot withdraw at all before maturity |

This is the power of overriding — same method name, completely different logic.

---

### 🔑 Hierarchical Inheritance in Lab 7

```
Account
  ├── SavingsAccount
  ├── CheckingAccount
  └── FixedDepositAccount

Shape
  ├── Circle
  ├── Rectangle
  ├── Triangle
  └── Polygon

Person
  ├── Student
  ├── Professor
  └── Staff

Media
  ├── Book
  ├── DVD
  └── CD

Currency
  ├── Dollar
  ├── Euro
  └── Rupee
```

---

### 🔑 Passing Object by Reference

From **Lab7/4.cpp**: `Course::registerStudent(Student &s)` takes a Student by reference.

```cpp
void registerStudent(Student &s) {
    cout << s.name << " registered in " << courseName << endl;
}

// In main:
Course c("CS301", "OOP", 3, "Dr. Khan", "Mon/Wed 10am");
c.registerStudent(s);  // s is a Student object
```

- `&` = pass by reference → no copy is made, you work with the original object.
- Efficient for large objects; changes inside the function affect the original.

---

### 🔑 Multiple Unrelated Classes Cooperating

Lab7/4.cpp has `Person → Student / Professor / Staff` AND a completely separate `Course` class. They cooperate:
- `Course::registerStudent(Student &s)` takes a `Student` object.
- This models real-world relationships without inheritance between `Course` and `Student`.

---

### 🔑 Complete Quick-Reference

| Lab7 File | Hierarchy | Special Concepts |
|---|---|---|
| `1.cpp` | `Account → 3 types` | Override `withdraw`, `calculateInterest`, `printStatement` |
| `2.cpp` | `Shape → 4 types` | Override `draw`, `calculateArea`, `calculatePerimeter` |
| `3.cpp` | `Currency → 3 types` | Override `convertToBase`, `displayCurrency`; pass by reference `convertTo(Currency &target)` |
| `4.cpp` | `Person → 3 types` + `Course` | Override `displayInfo`; passing object by reference |
| `5.cpp` | `Media → 3 types` | Override `displayInfo`; **function overloading** for `search()` |

---


## 🧠 Master Concept Checklist

### Procedural C++ (Lab 1)
- [ ] Functions, recursion, return values
- [ ] if/else, switch-case, loops
- [ ] Arrays

### Memory & Structs (Lab 1-2)
- [ ] Structs — defining and using
- [ ] Pointers — `*`, `&`, `->` 
- [ ] `new` / `delete` / `new[]` / `delete[]`
- [ ] Double pointers `**` for 2D arrays
- [ ] Dynamic resizing

### Classes & Encapsulation (Lab 2)
- [ ] `class`, `public`, `private`
- [ ] Getters and setters
- [ ] Member functions (behavior)

### Object Lifecycle (Lab 3)
- [ ] Default constructor
- [ ] Parameterized constructor
- [ ] Copy constructor — `const ClassName &obj`
- [ ] Default arguments in constructors
- [ ] Destructor — `~ClassName()`
- [ ] `this` pointer — resolving ambiguity
- [ ] Method chaining — `return *this`

### Static & Composition (Lab 4-5)
- [ ] `static` data members — shared across objects
- [ ] `static` member functions — `ClassName::funcName()`
- [ ] `static` definition outside class
- [ ] `const` member functions
- [ ] Composition — object as member of another class
- [ ] Initializer list — `Constructor() : memberObj(args)`
- [ ] Pointer to class object
- [ ] Constructor auto‑increment counters

### Inheritance (Lab 6)
- [ ] Single, multi‑level, multiple, hierarchical
- [ ] Diamond problem
- [ ] `virtual` inheritance — fix for diamond
- [ ] Calling base constructor in initializer list
- [ ] Scope resolution `Base::method()` from child

### Applied OOP (Lab 7)
- [ ] Method overriding
- [ ] Function overloading (same name, different params)
- [ ] Calling parent's overridden method inside child
- [ ] Passing objects by reference to functions
- [ ] Multiple classes collaborating

---

## ⚡ Quick Reminders for Exam

> **Static members** must be defined **outside** the class: `float ClassName::var = value;`

> **Copy constructor** signature is always: `ClassName(const ClassName &obj)`

> **Destructor** has **no return type** and **no parameters**: `~ClassName()`

> **Virtual inheritance** syntax: `class Child : virtual public Parent`

> **Method chaining** = return `*this` (a reference to the current object) from a member function

> **Initializer list** is the ONLY way to initialize a composed object with a parameterized constructor: `: memberObj(arg1, arg2)`

> **Diamond problem** = When two parent classes share a common grandparent. Fix = `virtual` inheritance on both parents.

> **Overloading** = same function name, **different parameters** (compile‑time). **Overriding** = same function name, **same parameters**, child replaces parent behavior.

---

*Good luck with your midterm!*
