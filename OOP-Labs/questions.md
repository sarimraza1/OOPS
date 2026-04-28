# C++ OOP — 30 Scenario-Based Exam Questions (Easy → Difficult)

> Styled after real mid-exam papers. Each question is a full scenario requiring class design, implementation, and OOP reasoning.

---

## 🟢 Level 1: Foundation Scenarios (Q1–Q10)

---

### Q1 — Library Book Tracker (Static Members)

A university library wants to track how many books are currently checked out. Design a class `Book` with:
- `title` (string), `author` (string), `isCheckedOut` (bool)
- A **static member** `checkedOutCount` that tracks the total number of currently checked out books across ALL Book objects.
- `checkout()` and `returnBook()` methods that update the static counter.
- A **static function** `getCheckedOutCount()` that returns the current count.

**In `main()`:**
- Create 3 Book objects on the stack.
- Check out 2 of them.
- Return 1.
- Print the total checked out count using the class name (no object).

**What OOP principle prevents `getCheckedOutCount()` from accessing `title`? Explain.**

---

### Q2 — Student ID Generator (Static + Scope Resolution)

A college assigns auto-incrementing IDs to students. Implement a class `Student` with:
- `name` (string), `id` (int)
- A `static int nextID` initialized to `1000` outside the class using the **scope resolution operator**.
- The constructor takes only `name` and auto-assigns `id = nextID++`.
- Define the member function `display()` **outside the class** using `::`.

**In `main()`:**
- Create students: `"Ali"`, `"Sara"`, `"Ahmed"`.
- Display all three.

**Expected Output:**
```
Ali (ID: 1000)
Sara (ID: 1001)
Ahmed (ID: 1002)
```

**Exam question:** What would happen if you forget `int Student::nextID = 1000;` outside the class?

---

### Q3 — Wallet App (this Pointer + Method Chaining)

Design a `Wallet` class for a mobile payment app:
- `ownerName` (string), `balance` (double)
- Constructor takes parameters with the **same names** as members — use `this->` to resolve.
- `deposit(double amount)` and `withdraw(double amount)` methods — both return `*this` for **method chaining**.
- `display()` prints owner and balance.

**In `main()`:**
```cpp
Wallet w("Sarim", 500.0);
w.deposit(200).withdraw(50).deposit(100).display();
```

**What is the final balance? Why does chaining work? What would break if the return type were `void` instead of `Wallet&`?**

---

### Q4 — Parking Lot (Object Pointers)

A parking lot management system stores vehicles dynamically. Implement:
- Class `Vehicle` with `plateNumber` (string), `type` (string — "Car"/"Bike").
- In `main()`, create **3 Vehicle objects on the heap** using pointers.
- Access and print each vehicle's info using the **arrow operator (`->`)**.
- Properly **deallocate** all memory.

**Trick question:** What happens if you write `delete vehicles;` instead of deleting each pointer individually? What is the difference between `delete` and `delete[]`?

---

### Q5 — Cricket Score Validator (Composition + Basic Logic)

A cricket app records a batsman's scores for 6 balls in one over. Design:
- Class `Over` with `int scores[6]` and `int validBalls`.
- Class `Batsman` with `string name` and an `Over currentOver;` (composition).
- `Batsman::playOver()` — prompts the user to enter score for each of the 6 balls. If a score is not between 0 and 6, it is **not counted** toward the total but the ball is still consumed.
- `Batsman::displayStats()` — shows name, each ball's score, and total valid runs.

**Why is this composition and not aggregation? What would change in memory layout if `Over` were a pointer instead?**

---

### Q6 — Employee Directory (Array of Pointers to Objects)

An HR system manages employees dynamically. Implement:
- Class `Employee` with `name` (string), `salary` (double).
- In `main()`, create an **array of 5 Employee pointers** (`Employee* team[5]`).
- Dynamically allocate each employee with user input.
- Display all employees.
- **Deallocate properly** — explain what happens if you only write `delete[] team;`.

**Draw the memory diagram** showing the stack array and the 5 heap objects.

---

### Q7 — Temperature Logger (Shallow Copy Bug)

A weather station logs temperatures. Implement:
- Class `Logger` with `double* readings` (dynamic array), `int count`.
- Constructor allocates `readings` on the heap.
- **Do NOT write a copy constructor** (use compiler default).

**In `main()`:**
```cpp
Logger today(5);
// ... fill with values ...
Logger backup = today;  // Shallow copy
```

- Modify `backup`'s first reading.
- Print `today`'s first reading.

**Questions:**
1. Why did `today`'s value also change?
2. Draw the memory diagram after the shallow copy.
3. Will the program crash at exit? Why?

---

### Q8 — Bank Account (Deep Copy)

Fix the `Logger` from Q7. Implement a `BankAccount` class:
- `accountHolder` (string), `double* transactions` (dynamic array), `int numTransactions`.
- Write a **deep copy constructor** and **deep copy assignment operator** (`operator=`).
- Include the **self-assignment guard** in `operator=`.
- Write a proper destructor.

**In `main()`:**
```cpp
BankAccount a("Ali", 5);
BankAccount b = a;       // Deep copy constructor
BankAccount c("Sara", 3);
c = a;                   // Deep copy assignment
```

**Prove independence** by modifying `a` and showing `b` and `c` are unchanged.

---

### Q9 — Classroom Attendance (Composition Destruction Order)

Design a system where:
- Class `Chair` prints `"Chair built"` / `"Chair removed"` in constructor/destructor.
- Class `Desk` prints `"Desk built"` / `"Desk removed"`.
- Class `Classroom` has a `Chair chair;` and a `Desk desk;` as members (composition) — **`chair` declared before `desk`**.
- `Classroom` prints `"Room ready"` / `"Room closed"` in its constructor/destructor body.

**In `main()`:** Create one `Classroom` object and let it go out of scope.

**Trace the exact output.** Then answer: If you swap the declaration order of `chair` and `desk` in the class, does the output change? What if you swap them in the initializer list but not in the class declaration?

---

### Q10 — Global vs Class vs Local (Scope Resolution)

Given this code:
```cpp
int score = 100;

class Game {
public:
    static int score;
    void showScores() {
        int score = 50;
        // Print all three scores from here
    }
};
int Game::score = 75;
```

**Write the three `cout` statements inside `showScores()` that print:**
```
Local: 50
Global: 100
Class: 75
```

**Which operator is used for each? Can you access the global `score` without `::`?**

---

## 🟡 Level 2: Multi-Concept Scenarios (Q11–Q20)

---

### Q11 — Hospital Patient System (Aggregation + Object Pointers)

A hospital ward doesn't own its patients — patients exist independently. Design:
- Class `Patient` with `name`, `disease`, `id`.
- Class `Ward` with `wardName`, `Patient** patients` (array of pointers), `int capacity`, `int currentCount`.
- `Ward` constructor takes `wardName` and `capacity`, dynamically allocates the pointer array.
- `addPatient(Patient* p)` — adds a patient pointer (does NOT create a new patient).
- `~Ward()` — frees the **pointer array only**, NOT the Patient objects.

**In `main()`:**
```cpp
Patient* p1 = new Patient("Ali", "Flu", 101);
Patient* p2 = new Patient("Sara", "Cold", 102);
Ward w("General", 10);
w.addPatient(p1);
w.addPatient(p2);
// Ward destroyed — patients still alive
```

**Why must the Ward NOT delete the Patient objects? What would happen if it did and main() also tries to use `p1` afterward?**

---

### Q12 — Online Shopping Cart (Composition + Deep Copy)

An e-commerce platform needs a cart that owns its items. Design:
- Class `Product` with `name` (string), `price` (double).
- Class `Cart` with `Product* items` (dynamic array), `int itemCount`.
- **Composition**: Cart owns the Product copies (not pointers to external products).
- Write: constructor, **deep copy constructor**, **deep copy assignment operator**, destructor.

**In `main()`:**
```cpp
Cart c1(3);
// Add products to c1...
Cart c2 = c1;    // Deep copy — independent cart
c2.updatePrice(0, 999.99);
c1.display();     // c1's price should be UNCHANGED
```

**What would go wrong if you used the default (shallow) copy constructor?**

---

### Q13 — Flight Reservation (Static + Array of Pointers + this)

An airline reservation system. Design:
- Class `Passenger` with `name`, `seatNumber`, and a **static int `totalPassengers`**.
- The constructor auto-assigns seat numbers using the static counter.
- `static int getTotal()` returns total passengers.
- `printBoardingPass()` uses `this->` to print seat info and also prints `this` (the address of the object).

**In `main()`:**
- Create `Passenger* manifest[4]` — array of 4 pointers, each dynamically allocated.
- Print all boarding passes. Verify `this` addresses differ.
- Delete passenger at index 1. Print total (should reflect the deletion if destructor decrements).
- Delete remaining passengers.

**What happens to `totalPassengers` if you forget to decrement in the destructor?**

---

### Q14 — University Course Registration (Aggregation + Shallow vs Deep)

Design:
- Class `Student` with `name`, `gpa`.
- Class `Course` with `courseName`, `Student** enrolled` (array of pointers — **aggregation**), `int maxStudents`, `int currentCount`.
- `enroll(Student* s)` adds a student pointer.

Now answer:
```cpp
Course oop("OOP", 30);
oop.enroll(s1);
oop.enroll(s2);

Course backup = oop;  // Default copy
```

1. **Is this a shallow or deep copy of the student pointers?**
2. **Draw the memory diagram** showing both `oop` and `backup` pointing to the same Student objects.
3. **Write a deep copy constructor** that creates new Student copies (turning aggregation into composition of copies).
4. **When would you want shallow vs deep here?** (Hint: think about whether backup should reflect real-time GPA changes.)

---

### Q15 — Smart Home System (Composition + Static + Scope Resolution)

Design a smart home controller:
- Class `Light` with `roomName` (string), `isOn` (bool), `static int totalLightsOn`.
- `turnOn()` / `turnOff()` update the static counter.
- Define `turnOn()` and `turnOff()` **outside the class** using `::`.
- Class `House` contains `Light lights[5]` (composition — array of 5 lights).
- `House::turnAllOn()` turns all lights on.
- In `main()`, create 2 House objects (10 lights total). Turn all on in house 1.

**Print `Light::totalLightsOn`. Explain why both houses share this count. What would go wrong if `totalLightsOn` were non-static?**

---

### Q16 — Digital Cricket Showdown (Full Scenario — Similar to Past Exam Q2)

Develop a program that organizes a digital cricket match where two players compete over **12 balls**. The game "Cricket Showdown" involves each player taking turns to score runs on every ball.

**Class `Player`:**
- `ballScores[12]` — array storing score for each ball.
- `playerName` (string).
- `totalScore` — count of total valid score.

**Class `Game`:**
- `playGame(Player& player)` — each player faces 12 balls. Prompt user for score each ball.
- `validateScore(int score)` — returns true if score is between 0 and 6 (inclusive). If invalid, the ball is still consumed but score is **not added** to total.
- `findWinner(Player& p1, Player& p2)` — determines winner based on total scores.
- `displayMatchScoreboard(Player& p1, Player& p2)` — displays:
  - Each player's name and score for each ball (in ascending ball order).
  - Average score and total score for each player.
  - Winner announcement.

**In `main()`:**
- Create two Player objects, play the game, display the scoreboard.

**Full implementation required.**

---

### Q17 — Music Playlist (Array of Pointers + Deep Copy + Destructor)

A music app manages playlists. Design:
- Class `Song` with `title` (string), `duration` (int seconds).
- Class `Playlist` with `name`, `Song** songs` (fully dynamic — array of pointers on heap, each Song on heap), `int capacity`, `int count`.
- Constructor allocates the pointer array.
- `addSong(string title, int dur)` — creates a `new Song` and adds it.
- **Deep copy constructor** — must deep copy every Song object AND the pointer array.
- **Destructor** — must delete every Song, then delete the pointer array.

**In `main()`:**
```cpp
Playlist rock("Rock Classics", 10);
rock.addSong("Bohemian Rhapsody", 354);
rock.addSong("Stairway to Heaven", 482);

Playlist copy = rock;  // Deep copy
// Modify copy — rock should be unaffected
```

**Write the destructor. Common bug: what happens if you only `delete[] songs` without the loop?**

---

### Q18 — Company Hierarchy (this Pointer + Aggregation + Static)

Design:
- Class `Employee` with `name`, `salary`, `Employee* manager` (aggregation — points to another Employee).
- `static int headcount`.
- Constructor increments headcount, destructor decrements.
- `promoteUnder(Employee& mgr)` — sets `this->manager = &mgr`. Uses `this` to ensure an employee can't be their own manager: `if (this == &mgr) { cout << "Can't self-manage!"; return; }`.
- `displayChain()` — prints `this` employee's name, then recursively prints manager's name up the chain.

**In `main()`:**
```cpp
Employee* ceo = new Employee("Boss", 200000);
Employee* mgr = new Employee("Manager", 100000);
Employee* dev = new Employee("Dev", 60000);

dev->promoteUnder(*mgr);
mgr->promoteUnder(*ceo);
dev->displayChain();

cout << Employee::headcount << endl;
delete dev; delete mgr; delete ceo;
cout << Employee::headcount << endl;
```

**Expected output chain:** `Dev → Manager → Boss`. **What happens if you call `ceo->promoteUnder(*ceo)`?**

---

### Q19 — Image Processing (2D Dynamic Memory + Deep Copy + Memory Leak)

Design:
- Class `Image` with `int** pixels` (2D dynamic array), `int width`, `int height`.
- Constructor allocates `height` rows, each row has `width` ints.
- Write a **deep copy constructor** that copies the entire 2D array.
- Write `operator=` with:
  1. Self-assignment check.
  2. Free ALL old memory (every row, then the row array).
  3. Allocate new memory and copy.
- Write destructor.

**Identify the memory leak in this buggy `operator=`:**
```cpp
Image& operator=(const Image& other) {
    if (this == &other) return *this;
    // FORGOT to free old pixels!
    width = other.width;
    height = other.height;
    pixels = new int*[height];
    for (int i = 0; i < height; i++) {
        pixels[i] = new int[width];
        for (int j = 0; j < width; j++)
            pixels[i][j] = other.pixels[i][j];
    }
    return *this;
}
```

**How many bytes are leaked if the old image was 100×100 of `int`?**

---

### Q20 — Game Inventory (Composition of Dynamic Object + Static + Pointers)

Design:
- Class `Weapon` with `name` (char* — dynamic C-string), `damage` (int), `static int totalWeapons`.
- Deep copy constructor for Weapon (allocates new char array).
- Class `Player` has `Weapon weapon;` (composition) and `string playerName`.
- `Player` copy should trigger Weapon's deep copy automatically.

**In `main()`:**
```cpp
Player p1("Hero", Weapon("Sword", 50));
Player p2 = p1;  // Does Weapon get deep copied?
```

**Prove that modifying `p1`'s weapon name does NOT affect `p2`. How many total weapons exist? Trace the static counter through constructors and the copy.**

---

## 🔴 Level 3: Exam-Grade Full Scenarios (Q21–Q30)

---

### Q21 — Space Exploration Agency (Full Scenario — Similar to Past Exam Q3)

In the vast expanse of space, a Space Exploration Agency manages missions, spacecraft, and astronauts. Design and implement:

**Class `Astronaut`:**
- `name` (string), `expertise` (string), `isAssigned` (bool — default false).
- Parameterized constructor using **member initialization list**.
- Destructor that prints astronaut name.

**Class `Spacecraft`:**
- `name` (string), `capacity` (int), `isReady` (bool).
- Parameterized constructor using **member initialization list**.

**Class `Mission`:**
- `missionName` (string), `duration` (int), `requirements` (string — e.g., "Pilot" or "Engineer").
- `destination` (string).
- `Spacecraft* spacecraft` (aggregation — pointer to external spacecraft).
- `Astronaut** crew` (dynamic array of pointers — aggregation).
- `int maxCrew`, `int currentCrew`.

**Implement:**
1. Mission constructor: takes all members except crew. Dynamically allocates `Astronaut*` array based on spacecraft capacity.
2. `assignSpacecraft(Spacecraft* sc)` — checks `isReady` first, then sets spacecraft and updates `maxCrew`.
3. `addAstronaut(Astronaut* a)` — checks: (a) not already assigned, (b) expertise matches requirements, (c) crew not full. If all pass, adds to crew and sets `isAssigned = true`.
4. Destructor frees the pointer array only (aggregation — does NOT delete astronauts).

**In `main()`:** Create astronauts, a spacecraft, a mission. Assign spacecraft, add astronauts (show both success and failure cases).

---

### Q22 — Social Media Platform (Aggregation + Deep Copy + Static + Array of Pointers)

Design a social media backend:

**Class `User`:**
- `username` (string), `static int totalUsers`, `int userId` (auto-assigned from static counter).
- Constructor, copy constructor (must increment totalUsers).

**Class `Post`:**
- `content` (char* — dynamic), `User* author` (aggregation).
- Deep copy constructor (deep copies content, shallow copies author pointer).
- Destructor frees content.

**Class `Feed`:**
- `Post** posts` (array of pointers, heap), `int capacity`, `int count`.
- `addPost(const char* content, User* author)` — creates new Post, adds to array.
- **Deep copy constructor** — deep copies every Post (which deep copies content, but shares author pointers).
- Destructor deletes all Posts and the array.

**In `main()`:**
```cpp
User u1("sarim_raza");
Feed f1(10);
f1.addPost("Hello World!", &u1);
f1.addPost("OOP is fun", &u1);

Feed f2 = f1;  // Deep copy
// Delete f1 — f2's posts should still work
// u1 should still be alive (aggregation)
```

**Draw the complete memory diagram after the deep copy. Label what's shared and what's independent.**

---

### Q23 — Hospital Management (Composition + Aggregation in Same Class)

Design:
- Class `Address` (composition candidate) — `city`, `street`, `zipCode`.
- Class `Doctor` — `name`, `specialization`, `Address address` (composition — doctor OWNS their address).
- Class `Hospital` — `hospitalName`, `Address address` (composition), `Doctor** staff` (aggregation — array of pointers to external doctors), `int maxDoctors`, `int currentDoctors`.

**Implement:**
- Hospital doesn't own doctors — they can work at multiple hospitals.
- Write deep copy constructor for Hospital: deep copies the Address (automatic via composition), but **shallow copies** the doctor pointers (aggregation — still point to same Doctor objects).
- Destructor deletes pointer array, NOT the doctors.

**In `main()`:** Create 3 doctors, 1 hospital. Add doctors to hospital. Copy the hospital. Delete original. Prove doctors still exist via the copy.

**Explain: Why is Address composition but Doctor is aggregation? What real-world relationship does each represent?**

---

### Q24 — Online Examination System (Static + this + Deep Copy Combined)

Design:
- Class `Question` with `char* text` (dynamic), `int marks`.
- Deep copy constructor, assignment operator, destructor (**Rule of Three**).

- Class `Exam` with:
  - `string title`, `Question* questions` (dynamic array — composition), `int totalQuestions`.
  - `static int examsCreated`.
  - Constructor increments static counter.
  - Deep copy constructor increments counter AND deep copies all Questions.
  - `Exam& addQuestion(const char* text, int marks)` — adds question, returns `*this` for chaining.

**In `main()`:**
```cpp
Exam midterm("OOP Mid");
midterm.addQuestion("What is this pointer?", 5)
       .addQuestion("Explain deep copy", 10)
       .addQuestion("Static vs non-static", 5);

Exam backup = midterm;  // Deep copy

cout << "Exams created: " << Exam::examsCreated << endl;  // 2
```

**Which concepts from the notes are used here? List ALL of them (at least 5).**

---

### Q25 — Vehicle Fleet Management (Full Destructor Chain + Memory Tracing)

```cpp
class Tire {
    static int count;
public:
    Tire()  { count++; cout << "T+" << count << " "; }
    ~Tire() { cout << "T-" << count << " "; count--; }
    static int getCount() { return count; }
};
int Tire::count = 0;

class Engine {
    int* hp;
public:
    Engine(int h) { hp = new int(h); cout << "E+ "; }
    Engine(const Engine& o) { hp = new int(*o.hp); cout << "EC "; }
    ~Engine() { cout << "E-(" << *hp << ") "; delete hp; }
};

class Car {
    Tire tires[4];    // Composition
    Engine engine;    // Composition
    Engine* spare;    // Aggregation
public:
    Car(int hp, Engine* s) : engine(hp), spare(s) { cout << "C+ "; }
    ~Car() { cout << "C- "; }
};

int main() {
    Engine* extra = new Engine(100);
    cout << endl;
    {
        Car c(200, extra);
        cout << endl;
        cout << "Tires: " << Tire::getCount() << endl;
    }
    cout << endl << "After car destroyed - Tires: " << Tire::getCount() << endl;
    delete extra;
    return 0;
}
```

**Trace the COMPLETE output line by line. How many objects exist at peak? Why is `extra` still alive after the car is destroyed?**

---

### Q26 — Database Record System (2-Level Deep Copy)

Design:
- Class `Field` with `char* name` (dynamic), `char* value` (dynamic).
- Deep copy constructor, `operator=`, destructor.

- Class `Record` with `Field* fields` (dynamic array of Field objects — composition), `int fieldCount`.
- Deep copy constructor must deep copy every Field (which in turn deep copies its char* members).
- This is a **two-level deep copy**. Draw the memory diagram.

**In `main()`:**
```cpp
Record r1(3);
r1.setField(0, "Name", "Ali");
r1.setField(1, "Age", "22");
r1.setField(2, "GPA", "3.8");

Record r2 = r1;  // Two-level deep copy
```

**How many `new` calls happen during the copy? (Answer: 1 for Field array + 2 per field × 3 fields = 7 total)**

---

### Q27 — Ride-Sharing App (All Pointer Types + Aggregation + Static)

Design a ride-sharing system:

**Class `Rider`** — `name`, `static int activeRiders`, dynamic `char* location`.

**Class `Driver`** — `name`, `static int activeDrivers`, `bool isAvailable`.

**Class `Ride`:**
- `Rider* rider` (aggregation — pointer to external Rider)
- `Driver* driver` (aggregation — pointer to external Driver)
- `static int totalRides`
- Uses `this` pointer in `confirmRide()` to print the Ride object's address.

**In `main()`:**
- Create `Rider* riders[3]` — array of pointers.
- Create `Driver* drivers[2]` — array of pointers.
- Create Ride objects matching riders to available drivers.
- Print all static counters.
- Properly clean up ALL memory.

**Write the complete cleanup code. What is the correct order of deletion? Can you delete a Rider before deleting the Ride that references them?**

---

### Q28 — School Timetable (Composition + Aggregation + Deep Copy + Static in One System)

Design a complete school timetable system:

**Class `Teacher`** — `name`, `subject`, `static int totalTeachers`. (Exists independently.)

**Class `TimeSlot`** — `day` (string), `startHour` (int), `endHour` (int). (Value type — composition.)

**Class `Lecture`:**
- `TimeSlot slot;` (composition — owns the time slot)
- `Teacher* teacher;` (aggregation — borrows a teacher)
- `string roomNumber`

**Class `Timetable`:**
- `Lecture* lectures` (dynamic array — composition of Lecture objects)
- `int lectureCount`, `int capacity`
- Deep copy constructor: must deep copy Lecture array (which deep copies TimeSlots automatically, but shallow copies Teacher pointers).
- Destructor.

**Implement the deep copy constructor. Explain:** For the copied timetable, which parts are independent copies and which are shared with the original? If a Teacher changes their name, does it affect both timetables?

---

### Q29 — Multiplayer Game Server (Grand Combo)

Design a game server managing rooms and players:

**Class `Player`:**
- `char* gamertag` (dynamic C-string), `int score`, `static int onlinePlayers`.
- **Rule of Three** fully implemented.
- Static function `getOnlineCount()`.

**Class `GameRoom`:**
- `string roomName`, `Player** players` (array of pointers — **aggregation**), `int maxPlayers`, `int currentPlayers`.
- `addPlayer(Player* p)` — adds if room not full.
- `removePlayer(int index)` — shifts array, does NOT delete the Player.
- `displayRoom()` — uses arrow operator on each pointer.
- `GameRoom(const GameRoom& other)` — **shallow copies** player pointers (aggregation copies).
- Destructor frees pointer array only.

**In `main()`:**
```cpp
Player* p1 = new Player("xX_Sniper_Xx", 0);
Player* p2 = new Player("NoobMaster69", 0);
Player* p3 = new Player("ProGamer", 0);

GameRoom lobby("Main Lobby", 5);
lobby.addPlayer(p1);
lobby.addPlayer(p2);
lobby.addPlayer(p3);

GameRoom backup = lobby;  // Shallow copy — both rooms reference same players

p1->score = 100;
backup.displayRoom();  // p1's score shows 100 — prove shared reference

lobby.removePlayer(0);              // Remove p1 from lobby
cout << Player::getOnlineCount();   // Still 3 — player not deleted

// Cleanup
delete p1; delete p2; delete p3;
cout << Player::getOnlineCount();   // 0
```

**Trace through and answer: After `delete p1`, what happens if `backup.displayRoom()` is called? (Dangling pointer!) How would you prevent this?**

---

### Q30 — University Learning Management System (The Ultimate Scenario)

Design a complete LMS that combines **every concept** from the notes:

**Class `Student`:**
- `char* name` (dynamic — for deep copy practice)
- `int rollNo`, `static int totalStudents`
- Constructor (using `this->` to resolve parameter shadowing)
- **Deep copy constructor**, **copy assignment operator**, **destructor** (Rule of Three)
- `static int getTotal()`

**Class `Assignment`:**
- `string title`, `int maxMarks`, `int* obtainedMarks` (dynamic — marks per student)
- Deep copy constructor, destructor
- `setMark(int studentIndex, int mark)` — validates 0 ≤ mark ≤ maxMarks

**Class `Course`:**
- `string courseName`, `string courseCode`
- `Student** enrolledStudents` (array of pointers — **aggregation**)
- `Assignment* assignments` (dynamic array — **composition**)
- `int maxStudents`, `int currentStudents`, `int maxAssignments`, `int currentAssignments`
- `static int totalCourses` (defined outside class with `::`)

**Implement:**
1. `Course` constructor: takes name, code, maxStudents, maxAssignments. Dynamically allocates both arrays.
2. `enrollStudent(Student* s)` — aggregation, just stores pointer.
3. `addAssignment(string title, int maxMarks)` — composition, creates Assignment in the array.
4. `Course(const Course& other)` — **deep copies** assignments (composition), **shallow copies** student pointers (aggregation).
5. `displayGradeSheet()` — prints each student's name (via `->`) and their marks for each assignment.
6. Destructor: deletes assignment array, deletes student pointer array, does NOT delete students.

**In `main()`:**
```cpp
Student* s1 = new Student("Ali", 1001);
Student* s2 = new Student("Sara", 1002);
Student* s3 = new Student("Ahmed", 1003);

Course oop("OOP", "CS200", 40, 5);
oop.enrollStudent(s1);
oop.enrollStudent(s2);
oop.enrollStudent(s3);

oop.addAssignment("Midterm", 100);
oop.addAssignment("Final", 100);

oop.displayGradeSheet();

Course backup = oop;  // Mixed deep/shallow copy

cout << "Total Students: " << Student::getTotal() << endl;   // 3
cout << "Total Courses: " << Course::totalCourses << endl;    // 2

// Cleanup — students deleted by main, not by Course
delete s1; delete s2; delete s3;
```

**This single question tests: Composition, Aggregation, Shallow Copy, Deep Copy, Static Members, Static Functions, Scope Resolution, Object Pointers, Array of Pointers, this Pointer, Rule of Three, and proper Memory Management.**

**Full implementation required.**

---

## Scoring Guide

| Score | Verdict |
|-------|---------|
| 25–30 fully correct | You're exam-ready. Walk in with confidence. |
| 18–24 | Solid but revisit the topics you missed. |
| 10–17 | Re-study notes.md, focus on memory diagrams. |
| < 10 | Start from fundamentals again. |

---

> **How to practice:** Write each answer **on paper first** (no IDE). That's what the exam will be. Time yourself: ~15 mins for Level 1, ~25 mins for Level 2, ~35 mins for Level 3.
