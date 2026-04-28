# Theme Park Management System

A C++ terminal-based Object-Oriented application designed to manage the core operations of a theme park. This system uses standard C++ file handling to persist data and provides an interactive command-line interface for ease of use.

## 🚀 Features

The system is built on strong **Object-Oriented Programming (OOP)** principles such as Abstraction, Encapsulation, Polymorphism, and Inheritance. It supports the management of several entities:

*   **Rides Management:** Track ride details, operational status (Operational / Maintenance), and pricing.
*   **Visitor Management:** Register and track visitor information, including age and contact details.
*   **Ticketing System:** Issue tickets mapping visitors to specific rides and track amounts.
*   **Staff & Users:** Manage employees and system users.
*   **Inventory & Events:** Oversee park inventory, plan special events, and record feedback.
*   **Data Persistence:** All records are consistently loaded from and saved to simple `.txt` files (e.g., `Rides.txt`, `Visitors.txt`, `Tickets.txt`, etc.).
*   **Interactive Command Line UI:** Intuitive console menus with colored outputs (using Windows Console API) and robust error handling for user inputs.

## ⚙️ Program Flow

1.  **Launch:** When the program starts, it loads existing data from the `.txt` database files into memory (Standard Template Library vectors).
2.  **Main Menu:** The user is presented with a colored terminal UI allowing them to navigate between different management modules (e.g., Manage Rides, Manage Visitors, Issue Tickets).
3.  **Interaction:** 
    *   Functions utilize C++ abstractions and templates to safely read user inputs.
    *   System performs CRUD operations (Create, Read, Update, Delete) on the classes (`Visitor`, `Ride`, `Ticket`, etc.).
4.  **Save & Exit:** On saving/modifying or gracefully exiting, the `serialize()` polymorphic methods are called on the entities, writing the up-to-date data back into their respective text files to ensure data persistence across sessions.

## 🛠️ Tech Stack & Concepts Used

*   **Language:** C++
*   **Concepts:** OOP (Classes, Virtual Functions/Polymorphism, Inheritance), Operator Overloading, Templates, and lambda functions (`<algorithm>`).
*   **Storage:** Local Text Files (Deserialization via `<fstream>` and `<sstream>`)
*   **UI:** Windows Command Prompt Console Colors (`<windows.h>`)

## 🖥️ How to Run

1.  Requires a standard C++ compiler (e.g., MinGW/GCC) targeting a Windows environment (due to `windows.h` usage).
2.  Compile the main file: 
    ```bash
    g++ ThemeParkProject.cpp -o ThemeParkProject.exe
    ```
3.  Run the generated executable:
    ```bash
    ThemeParkProject.exe
    ```

## 👥 Contributors

*   **Sarim**
*   **Abbas**
