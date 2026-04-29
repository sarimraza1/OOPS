# Theme Park Management System

A robust C++ terminal application for managing theme park operations with persistent storage.

## 🚀 Key Features
- **Role-Based Access**: Separate portals for Staff and Managers.
- **Entity Management**: Comprehensive CRUD for Visitors, Rides, Tickets, Events, and Staff.
- **Inventory Tracking**: Monitor park supplies and costs.
- **Revenue & Feedback**: Automated revenue reports and visitor feedback analysis.
- **Data Persistence**: 8-file database system using pipe-delimited text files.
- **Robust UI**: Colored Windows console interface with template-based input validation.

## 🛠️ Core OOP Implementation
- **Inheritance & Polymorphism**: Extends `ParkEntity` base class with dynamic dispatch for entity lists.
- **Encapsulation**: Private data members with controlled access via public getters.
- **Abstraction**: Interface enforcement through pure virtual functions.
- **Operator Overloading**: Custom operators for ticket comparisons and formatted output.
- **STL & Templates**: Extensive use of `std::vector`, algorithms, and custom template utilities.

## 🖥️ Getting Started
1. **Compile**: `g++ ThemeParkProject.cpp -o ThemePark.exe`
2. **Run**: `ThemePark.exe`

### Default Credentials
- **Staff**: `staff1` / `pass123`
- **Manager**: `manager1` / `admin123`

## 👥 Contributors
- **Sarim**
- **Abbas**
