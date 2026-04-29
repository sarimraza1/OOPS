#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>

#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;


class ConsoleColor
{
public:
    enum Color
    {
        BLACK = 0,
        CYAN = 3,
        GREEN = 2,
        RED = 4,
        WHITE = 7
    };

    static void setColor(Color foreground)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, foreground);
    }

    static void reset()
    {
        setColor(WHITE);
    }

    static void printTitle(const string &text)
    {
        setColor(CYAN);
        cout << text;
        reset();
    }

    static void printSuccess(const string &text)
    {
        setColor(GREEN);
        cout << text;
        reset();
    }

    static void printError(const string &text)
    {
        setColor(RED);
        cout << text;
        reset();
    }
};


template <typename T>
T readNumber(const string &prompt, T minValue, T maxValue)
{
    T value;
    while (true)
    {
        cout << prompt;
        if (cin >> value && value >= minValue && value <= maxValue)
        {
            cin.ignore(10000, '\n');
            return value;
        }
        cout << "Invalid input. Try again.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

template <typename T>
const T *findById(const vector<T> &items, int id)
{
    auto it = find_if(items.begin(), items.end(), [id](const T &item)
                      { return item.getId() == id; });

    return (it == items.end()) ? nullptr : &(*it);
}


class ParkEntity
{
protected:
    int id;
    string name;

public:
    ParkEntity(int id, const string &name) : id(id), name(name) {}
    virtual ~ParkEntity() {}

    int getId() const { return id; }
    string getName() const { return name; }

    virtual void display() const = 0;
    virtual string serialize() const = 0;
};


class Visitor : public ParkEntity
{
    int age;
    string email;
    static int nextId;

public:
    Visitor(const string &name, int age, const string &email)
        : ParkEntity(nextId++, name), age(age), email(email) {}

    Visitor(int id, const string &name, int age, const string &email)
        : ParkEntity(id, name), age(age), email(email)
    {
        if (id >= nextId)
            nextId = id + 1;
    }

    ~Visitor() {}

    int getAge() const { return age; }
    string getEmail() const { return email; }

    void display() const override
    {
        cout << "Visitor ID: " << id
             << " | Name: " << name
             << " | Age: " << age
             << " | Email: " << email << "\n";
    }

    string serialize() const override
    {
        stringstream ss;
        ss << id << '|' << name << '|' << age << '|' << email;
        return ss.str();
    }
};

int Visitor::nextId = 1;


class Ride : public ParkEntity
{
private:
    double price;
    bool operational;
    static int nextId;

public:
    Ride(const string &name, double price, bool operational)
        : ParkEntity(nextId++, name), price(price), operational(operational) {}

    Ride(int id, const string &name, double price, bool operational)
        : ParkEntity(id, name), price(price), operational(operational)
    {
        if (id >= nextId)
            nextId = id + 1;
    }

    ~Ride() {}

    double getPrice() const { return price; }
    bool isOperational() const { return operational; }

    void display() const override
    {
        cout << "Ride ID: " << id
             << " | Name: " << name
             << " | Price: $" << fixed << setprecision(2) << price
             << " | Status: " << (operational ? "Operational" : "Maintenance") << "\n";
    }

    string serialize() const override
    {
        stringstream ss;
        ss << id << '|' << name << '|' << fixed << setprecision(2) << price << '|' << operational;
        return ss.str();
    }
};

int Ride::nextId = 1;


class Ticket
{
private:
    int id;
    int visitorId;
    int rideId;
    double amount;
    static int nextId;

public:
    Ticket(int visitorId, int rideId, double amount)
        : id(nextId++), visitorId(visitorId), rideId(rideId), amount(amount) {}

    Ticket(int id, int visitorId, int rideId, double amount)
        : id(id), visitorId(visitorId), rideId(rideId), amount(amount)
    {
        if (id >= nextId)
            nextId = id + 1;
    }

    ~Ticket() {}

    int getId() const { return id; }
    int getVisitorId() const { return visitorId; }
    int getRideId() const { return rideId; }
    double getAmount() const { return amount; }

    string serialize() const
    {
        stringstream ss;
        ss << id << '|' << visitorId << '|' << rideId << '|' << fixed << setprecision(2) << amount;
        return ss.str();
    }

    
    double operator+(const Ticket &other) const { return amount + other.amount; }
    bool operator<(const Ticket &other) const { return amount < other.amount; }

    friend void applyDiscount(Ticket &ticket, double percentage);
    friend ostream &operator<<(ostream &os, const Ticket &ticket);
};

int Ticket::nextId = 1001;

void applyDiscount(Ticket &ticket, double percentage)
{
    if (percentage < 0 || percentage > 100)
        throw invalid_argument("Discount must be between 0 and 100.");

    ticket.amount -= ticket.amount * (percentage / 100.0);
}

ostream &operator<<(ostream &os, const Ticket &ticket)
{
    os << "Ticket ID: " << ticket.id
       << " | Visitor ID: " << ticket.visitorId
       << " | Ride ID: " << ticket.rideId
       << " | Amount: $" << fixed << setprecision(2) << ticket.amount;
    return os;
}


class Event : public ParkEntity
{
private:
    string date;
    int capacity;
    int registered;
    static int nextId;

public:
    Event(const string &name, const string &date, int capacity)
        : ParkEntity(nextId++, name), date(date), capacity(capacity), registered(0) {}

    Event(int id, const string &name, const string &date, int capacity, int registered)
        : ParkEntity(id, name), date(date), capacity(capacity), registered(registered)
    {
        if (id >= nextId)
            nextId = id + 1;
    }

    ~Event() {}

    string getDate() const { return date; }
    int getCapacity() const { return capacity; }
    int getRegistered() const { return registered; }

    void registerVisitor()
    {
        if (registered < capacity)
            registered++;
        else
            throw runtime_error("Event is full.");
    }

    void display() const override
    {
        cout << "Event ID: " << id
             << " | Name: " << name
             << " | Date: " << date
             << " | Registered: " << registered << "/" << capacity << "\n";
    }

    string serialize() const override
    {
        stringstream ss;
        ss << id << '|' << name << '|' << date << '|' << capacity << '|' << registered;
        return ss.str();
    }
};

int Event::nextId = 2001;


class Staff : public ParkEntity
{
private:
    string role;
    double salary;
    static int nextId;

public:
    Staff(const string &name, const string &role, double salary)
        : ParkEntity(nextId++, name), role(role), salary(salary) {}

    Staff(int id, const string &name, const string &role, double salary)
        : ParkEntity(id, name), role(role), salary(salary)
    {
        if (id >= nextId)
            nextId = id + 1;
    }

    ~Staff() {}

    string getRole() const { return role; }
    double getSalary() const { return salary; }

    void display() const override
    {
        cout << "Staff ID: " << id
             << " | Name: " << name
             << " | Role: " << role
             << " | Salary: $" << fixed << setprecision(2) << salary << "\n";
    }

    string serialize() const override
    {
        stringstream ss;
        ss << id << '|' << name << '|' << role << '|' << fixed << setprecision(2) << salary;
        return ss.str();
    }
};

int Staff::nextId = 3001;


class Feedback
{
private:
    int id;
    int visitorId;
    int rating;
    string comment;
    static int nextId;

public:
    Feedback(int visitorId, int rating, const string &comment)
        : id(nextId++), visitorId(visitorId), rating(rating), comment(comment) {}

    Feedback(int id, int visitorId, int rating, const string &comment)
        : id(id), visitorId(visitorId), rating(rating), comment(comment)
    {
        if (id >= nextId)
            nextId = id + 1;
    }

    ~Feedback() {}

    int getId() const { return id; }
    int getVisitorId() const { return visitorId; }
    int getRating() const { return rating; }
    string getComment() const { return comment; }

    void display() const
    {
        cout << "Feedback ID: " << id
             << " | Visitor: " << visitorId
             << " | Rating: " << rating << "/5"
             << " | Comment: " << comment << "\n";
    }

    string serialize() const
    {
        stringstream ss;
        ss << id << '|' << visitorId << '|' << rating << '|' << comment;
        return ss.str();
    }

    friend double calculateAverageRating(const vector<Feedback> &feedbacks);
};

int Feedback::nextId = 5001;

double calculateAverageRating(const vector<Feedback> &feedbacks)
{
    if (feedbacks.empty())
        return 0.0;

    double sum = 0.0;
    for (const auto &f : feedbacks)
        sum += f.rating;

    return sum / feedbacks.size();
}


class Inventory : public ParkEntity
{
private:
    int quantity;
    double costPerItem;
    static int nextId;

public:
    Inventory(const string &itemName, int quantity, double costPerItem)
        : ParkEntity(nextId++, itemName), quantity(quantity), costPerItem(costPerItem) {}

    Inventory(int id, const string &itemName, int quantity, double costPerItem)
        : ParkEntity(id, itemName), quantity(quantity), costPerItem(costPerItem)
    {
        if (id >= nextId)
            nextId = id + 1;
    }

    ~Inventory() {}

    int getQuantity() const { return quantity; }
    double getCostPerItem() const { return costPerItem; }

    void updateQuantity(int change)
    {
        if (quantity + change < 0)
            throw runtime_error("Insufficient inventory.");
        quantity += change;
    }

    void display() const override
    {
        cout << "Inventory ID: " << id
             << " | Item: " << name
             << " | Quantity: " << quantity
             << " | Cost per Item: $" << fixed << setprecision(2) << costPerItem << "\n";
    }

    string serialize() const override
    {
        stringstream ss;
        ss << id << '|' << name << '|' << quantity << '|' << fixed << setprecision(2) << costPerItem;
        return ss.str();
    }
};

int Inventory::nextId = 4001;


class User
{
protected:
    int userId;
    string username;
    string password;
    string role; 

public:
    User(int userId, const string &username, const string &password, const string &role)
        : userId(userId), username(username), password(password), role(role) {}

    virtual ~User() {}

    int getUserId() const { return userId; }
    string getUsername() const { return username; }
    string getRole() const { return role; }

    bool authenticate(const string &pwd) const { return password == pwd; }

    virtual string serialize() const
    {
        stringstream ss;
        ss << userId << '|' << username << '|' << password << '|' << role;
        return ss.str();
    }
};


class ThemeParkSystem
{
private:
    vector<Visitor> visitors;
    vector<Ride> rides;
    vector<Ticket> tickets;
    vector<Event> events;
    vector<Staff> staff;
    vector<Feedback> feedbacks;
    vector<Inventory> inventory;
    vector<User> users;

    const string visitorsFile = "Visitors.txt";
    const string ridesFile = "Rides.txt";
    const string ticketsFile = "Tickets.txt";
    const string eventsFile = "Events.txt";
    const string staffFile = "Staff.txt";
    const string feedbackFile = "Feedback.txt";
    const string inventoryFile = "Inventory.txt";
    const string usersFile = "Users.txt";

    User *currentUser = nullptr;

public:
    ThemeParkSystem()
    {
        loadData();
        initializeDefaultUsers();
    }

    ~ThemeParkSystem()
    {
        saveData();
    }

    void run()
    {
        while (true)
        {
            cout << "\n";
            ConsoleColor::printTitle("===== THEME PARK MANAGEMENT SYSTEM =====\n");
            cout << "1. Login as Staff\n";
            cout << "2. Login as Manager\n";
            cout << "0. Exit\n\n";

            int choice = readNumber<int>("Enter choice: ", 0, 2);

            try
            {
                switch (choice)
                {
                case 1:
                    if (login("Staff"))
                        staffPortal();
                    break;
                case 2:
                    if (login("Manager"))
                        managerPortal();
                    break;
                case 0:
                    saveData();
                    ConsoleColor::printSuccess("Thank you for visiting our theme park!\n");
                    return;
                }
            }
            catch (const exception &ex)
            {
                ConsoleColor::printError("Error: ");
                cout << ex.what() << "\n";
            }
        }
    }

private:
    bool login(const string &role)
    {
        string username, password;
        cout << "\nEnter username: ";
        getline(cin, username);
        cout << "Enter password: ";
        getline(cin, password);

        for (auto &user : users)
        {
            if (user.getRole() == role && user.getUsername() == username && user.authenticate(password))
            {
                currentUser = &user;
                cout << "Login successful. Welcome, " << currentUser->getUsername() << "!\n";
                return true;
            }
        }

        cout << "Invalid credentials.\n";
        return false;
    }

    void staffPortal()
    {
        cout << "\n";
        ConsoleColor::printTitle("--- STAFF PORTAL ---\n");
        cout << "\n";

        while (true)
        {
            cout << "=== Staff Menu ===\n";
            cout << "1. Register Visitor\n";
            cout << "2. View Available Rides\n";
            cout << "3. View Available Events\n";
            cout << "4. Book Ticket for Visitor\n";
            cout << "5. View All Visitors\n";
            cout << "6. Logout\n\n";

            int choice = readNumber<int>("Enter choice: ", 1, 6);

            try
            {
                switch (choice)
                {
                case 1:
                    addVisitor();
                    break;
                case 2:
                    listRides();
                    break;
                case 3:
                    listEvents();
                    break;
                case 4:
                    bookTicket();
                    break;
                case 5:
                    listVisitors();
                    break;
                case 6:
                    ConsoleColor::printSuccess("Logged out successfully.\n");
                    currentUser = nullptr;
                    return;
                }
            }
            catch (const exception &ex)
            {
                ConsoleColor::printError("Error: ");
                cout << ex.what() << "\n";
            }
        }
    }

    void managerPortal()
    {
        cout << "\n";
        ConsoleColor::printTitle("--- MANAGER PORTAL ---\n");
        cout << "\n";

        while (true)
        {
            cout << "=== Manager Menu ===\n";
            cout << "1. Add Staff Member\n";
            cout << "2. Add Ride\n";
            cout << "3. Add Event\n";
            cout << "4. Add Inventory Item\n";
            cout << "5. View Feedback\n";
            cout << "6. View Revenue Report\n";
            cout << "7. View All Staff\n";
            cout << "8. View All Rides\n";
            cout << "9. View All Events\n";
            cout << "10. View All Inventory\n";
            cout << "11. Save Data\n";
            cout << "12. Logout\n\n";

            int choice = readNumber<int>("Enter choice: ", 1, 12);

            try
            {
                switch (choice)
                {
                case 1:
                    addStaff();
                    break;
                case 2:
                    addRide();
                    break;
                case 3:
                    addEvent();
                    break;
                case 4:
                    addInventory();
                    break;
                case 5:
                    listFeedback();
                    break;
                case 6:
                    showRevenueReport();
                    break;
                case 7:
                    listStaff();
                    break;
                case 8:
                    listRides();
                    break;
                case 9:
                    listEvents();
                    break;
                case 10:
                    listInventory();
                    break;
                case 11:
                    saveData();
                    ConsoleColor::printSuccess("Data saved.\n");
                    break;
                case 12:
                    ConsoleColor::printSuccess("Logged out successfully.\n");
                    currentUser = nullptr;
                    saveData();
                    return;
                }
            }
            catch (const exception &ex)
            {
                ConsoleColor::printError("Error: ");
                cout << ex.what() << "\n";
            }
        }
    }

    void initializeDefaultUsers()
    {
        if (users.empty())
        {
            users.emplace_back(1001, "staff1", "pass123", "Staff");
            users.emplace_back(2001, "manager1", "admin123", "Manager");
            saveUsers();
        }
    }

private:
    void addVisitor()
    {
        string name, email;
        cout << "Enter visitor name: ";
        getline(cin, name);
        int age = readNumber<int>("Enter age: ", 1, 120);
        cout << "Enter email: ";
        getline(cin, email);

        visitors.emplace_back(name, age, email);
        ConsoleColor::printSuccess("✓ Visitor added.\n");
    }

    void addRide()
    {
        string name;
        cout << "Enter ride name: ";
        getline(cin, name);

        double price = readNumber<double>("Enter ride price: ", 0.0, 10000.0);
        int statusChoice = readNumber<int>("Status (1 Operational, 2 Maintenance): ", 1, 2);

        rides.emplace_back(name, price, statusChoice == 1);
        ConsoleColor::printSuccess("✓ Ride added.\n");
    }

    void addEvent()
    {
        string name, date;
        cout << "Enter event name: ";
        getline(cin, name);
        cout << "Enter event date (YYYY-MM-DD): ";
        getline(cin, date);
        int capacity = readNumber<int>("Enter capacity: ", 1, 10000);

        events.emplace_back(name, date, capacity);
        ConsoleColor::printSuccess("✓ Event added.\n");
    }

    void addStaff()
    {
        string name, role;
        cout << "Enter staff name: ";
        getline(cin, name);
        cout << "Enter role (Manager/Operator/Guide): ";
        getline(cin, role);
        double salary = readNumber<double>("Enter monthly salary: ", 0.0, 100000.0);

        staff.emplace_back(name, role, salary);
        ConsoleColor::printSuccess("✓ Staff member added.\n");
    }

    void addInventory()
    {
        string itemName;
        cout << "Enter item name: ";
        getline(cin, itemName);
        int quantity = readNumber<int>("Enter quantity: ", 0, 100000);
        double cost = readNumber<double>("Enter cost per item: ", 0.0, 1000.0);

        inventory.emplace_back(itemName, quantity, cost);
        ConsoleColor::printSuccess("✓ Inventory item added.\n");
    }

    void bookTicket()
    {
        if (visitors.empty() || rides.empty())
            throw runtime_error("Add at least one visitor and one ride first.");

        listVisitors();
        int visitorId = readNumber<int>("Enter Visitor ID: ", 1, 1000000);

        const Visitor *visitor = findById(visitors, visitorId);
        if (!visitor)
            throw runtime_error("Visitor ID not found.");

        listRides();
        int rideId = readNumber<int>("Enter Ride ID: ", 1, 1000000);

        const Ride *ride = findById(rides, rideId);
        if (!ride)
            throw runtime_error("Ride ID not found.");
        if (!ride->isOperational())
            throw runtime_error("Ride is currently under maintenance.");

        Ticket ticket(visitorId, rideId, ride->getPrice());

        int discountChoice = readNumber<int>("Apply student discount 10%? (1 Yes, 2 No): ", 1, 2);
        if (discountChoice == 1)
            applyDiscount(ticket, 10.0);

        tickets.push_back(ticket);
        cout << "Ticket booked successfully.\n";
        cout << ticket << "\n";
    }

    void listVisitors() const
    {
        cout << "\n--- Visitors ---\n";
        if (visitors.empty())
        {
            cout << "No visitors found.\n";
            return;
        }

        vector<const ParkEntity *> entities;
        for (const auto &v : visitors)
            entities.push_back(&v);

        for (const auto *e : entities)
            e->display();
    }

    void listRides() const
    {
        cout << "\n--- Rides ---\n";
        if (rides.empty())
        {
            cout << "No rides found.\n";
            return;
        }

        vector<const ParkEntity *> entities;
        for (const auto &r : rides)
            entities.push_back(&r);

        for (const auto *e : entities)
            e->display();
    }

    void listEvents() const
    {
        cout << "\n--- Events ---\n";
        if (events.empty())
        {
            cout << "No events found.\n";
            return;
        }

        vector<const ParkEntity *> entities;
        for (const auto &e : events)
            entities.push_back(&e);

        for (const auto *ent : entities)
            ent->display();
    }

    void listStaff() const
    {
        cout << "\n--- Staff Members ---\n";
        if (staff.empty())
        {
            cout << "No staff members found.\n";
            return;
        }

        vector<const ParkEntity *> entities;
        for (const auto &s : staff)
            entities.push_back(&s);

        for (const auto *e : entities)
            e->display();
    }

    void listInventory() const
    {
        cout << "\n--- Inventory ---\n";
        if (inventory.empty())
        {
            cout << "No inventory items found.\n";
            return;
        }

        vector<const ParkEntity *> entities;
        for (const auto &i : inventory)
            entities.push_back(&i);

        for (const auto *e : entities)
            e->display();
    }

    void listTickets()
    {
        cout << "\n--- Tickets ---\n";
        if (tickets.empty())
        {
            cout << "No tickets found.\n";
            return;
        }

        sort(tickets.begin(), tickets.end());

        for (const auto &ticket : tickets)
            cout << ticket << "\n";
    }

    void listFeedback() const
    {
        cout << "\n--- Feedback ---\n";
        if (feedbacks.empty())
        {
            cout << "No feedback found.\n";
            return;
        }

        for (const auto &fb : feedbacks)
            fb.display();

        cout << "\nAverage Rating: " << fixed << setprecision(2) << calculateAverageRating(feedbacks) << "/5\n";
    }

    void showRevenueReport() const
    {
        double revenue = 0.0;
        for (const auto &t : tickets)
            revenue += t.getAmount();

        cout << "\n===== REVENUE REPORT =====\n";
        cout << "Total Ticket Revenue: $" << fixed << setprecision(2) << revenue << "\n";
    }

    void saveData() const
    {
        ofstream vFile(visitorsFile);
        for (const auto &v : visitors)
            vFile << v.serialize() << "\n";

        ofstream rFile(ridesFile);
        for (const auto &r : rides)
            rFile << r.serialize() << "\n";

        ofstream tFile(ticketsFile);
        for (const auto &t : tickets)
            tFile << t.serialize() << "\n";

        ofstream eFile(eventsFile);
        for (const auto &e : events)
            eFile << e.serialize() << "\n";

        ofstream sFile(staffFile);
        for (const auto &s : staff)
            sFile << s.serialize() << "\n";

        ofstream fFile(feedbackFile);
        for (const auto &f : feedbacks)
            fFile << f.serialize() << "\n";

        ofstream iFile(inventoryFile);
        for (const auto &i : inventory)
            iFile << i.serialize() << "\n";

        saveUsers();
    }

    void saveUsers() const
    {
        ofstream uFile(usersFile);
        for (const auto &u : users)
            uFile << u.serialize() << "\n";
    }

    void loadData()
    {
        loadUsers();
        loadVisitors();
        loadRides();
        loadTickets();
        loadEvents();
        loadStaff();
        loadFeedback();
        loadInventory();
    }

    void loadVisitors()
    {
        ifstream file(visitorsFile);
        string line;
        while (getline(file, line))
        {
            if (line.empty())
                continue;

            stringstream ss(line);
            string idStr, name, ageStr, email;
            getline(ss, idStr, '|');
            getline(ss, name, '|');
            getline(ss, ageStr, '|');
            getline(ss, email, '|');

            visitors.emplace_back(stoi(idStr), name, stoi(ageStr), email);
        }
    }

    void loadRides()
    {
        ifstream file(ridesFile);
        string line;
        while (getline(file, line))
        {
            if (line.empty())
                continue;

            stringstream ss(line);
            string idStr, name, priceStr, statusStr;
            getline(ss, idStr, '|');
            getline(ss, name, '|');
            getline(ss, priceStr, '|');
            getline(ss, statusStr, '|');

            rides.emplace_back(stoi(idStr), name, stod(priceStr), statusStr == "1");
        }
    }

    void loadTickets()
    {
        ifstream file(ticketsFile);
        string line;
        while (getline(file, line))
        {
            if (line.empty())
                continue;

            stringstream ss(line);
            string idStr, visitorIdStr, rideIdStr, amountStr;
            getline(ss, idStr, '|');
            getline(ss, visitorIdStr, '|');
            getline(ss, rideIdStr, '|');
            getline(ss, amountStr, '|');

            tickets.emplace_back(stoi(idStr), stoi(visitorIdStr), stoi(rideIdStr), stod(amountStr));
        }
    }

    void loadEvents()
    {
        ifstream file(eventsFile);
        string line;
        while (getline(file, line))
        {
            if (line.empty())
                continue;

            stringstream ss(line);
            string idStr, name, date, capacityStr, registeredStr;
            getline(ss, idStr, '|');
            getline(ss, name, '|');
            getline(ss, date, '|');
            getline(ss, capacityStr, '|');
            getline(ss, registeredStr, '|');

            events.emplace_back(stoi(idStr), name, date, stoi(capacityStr), stoi(registeredStr));
        }
    }

    void loadStaff()
    {
        ifstream file(staffFile);
        string line;
        while (getline(file, line))
        {
            if (line.empty())
                continue;

            stringstream ss(line);
            string idStr, name, role, salaryStr;
            getline(ss, idStr, '|');
            getline(ss, name, '|');
            getline(ss, role, '|');
            getline(ss, salaryStr, '|');

            staff.emplace_back(stoi(idStr), name, role, stod(salaryStr));
        }
    }

    void loadFeedback()
    {
        ifstream file(feedbackFile);
        string line;
        while (getline(file, line))
        {
            if (line.empty())
                continue;

            stringstream ss(line);
            string idStr, visitorIdStr, ratingStr, comment;
            getline(ss, idStr, '|');
            getline(ss, visitorIdStr, '|');
            getline(ss, ratingStr, '|');
            getline(ss, comment, '|');

            feedbacks.emplace_back(stoi(idStr), stoi(visitorIdStr), stoi(ratingStr), comment);
        }
    }

    void loadInventory()
    {
        ifstream file(inventoryFile);
        string line;
        while (getline(file, line))
        {
            if (line.empty())
                continue;

            stringstream ss(line);
            string idStr, itemName, quantityStr, costStr;
            getline(ss, idStr, '|');
            getline(ss, itemName, '|');
            getline(ss, quantityStr, '|');
            getline(ss, costStr, '|');

            inventory.emplace_back(stoi(idStr), itemName, stoi(quantityStr), stod(costStr));
        }
    }

    void loadUsers()
    {
        ifstream file(usersFile);
        string line;
        while (getline(file, line))
        {
            if (line.empty())
                continue;

            stringstream ss(line);
            string userIdStr, username, password, role;
            getline(ss, userIdStr, '|');
            getline(ss, username, '|');
            getline(ss, password, '|');
            getline(ss, role, '|');

            users.emplace_back(stoi(userIdStr), username, password, role);
        }
    }
};

int main()
{
    ThemeParkSystem app;
    app.run();
    return 0;
}
