# Zoo Management System ~ OOP Project
## Project Description:
This OOP project demonstrates a comprehensive Zoo Management System developed using C++ with extensive use of object-oriented programming principles such as inheritance, polymorphism, encapsulation, and exception handling.

### The project comprises several classes, including Animal, Ticket, Cost, Employee, Caretaker, Cashier, Reception, Product, Food, Road, Asphalt, Gravel, and multiple specialized veterinarian classes. Each class is designed to model real-world entities and relationships within a zoo setting, showcasing the versatility and power of OOP.

### Core Classes:
- **Animal**: Manages animal details (type, location, name) with methods for getting and setting these properties. Overloaded ostream operator for easy display.
- **Ticket**: Handles ticket information (price, type) with a static counter to track the number of tickets. Includes methods to get, set, and display ticket details.
- **Cost**: Represents various costs associated with zoo operations, such as animal food, employee salaries, rent, and maintenance. Provides getters and setters for these costs and an overloaded ostream operator for display.

### Employee Hierarchy:
- **Employee**: Base class for employees, holding common attributes like name, age, sex, and tenure.
- **Caretaker** and **Cashier**: Derived from Employee, these classes add specific attributes and methods relevant to their roles.
- **Contract**: Used to manage employment contracts, integrating with the Employee class through multiple inheritance when defining a Caretaker.

### Specialized Classes:
- **Reception**: Inherits from Animal, adding attributes for country of origin and temperature preference.
- **Product** and **Food**: Abstract base class and derived class for managing zoo products, demonstrating polymorphism and pure virtual functions.
- **Road**, **Asphalt**, and **Gravel**: Illustrates polymorphism with a base class and derived classes representing different types of roads within the zoo.

### Exception Handling:
- Custom exception classes (`ZooException` and `NewZooException`) are used to handle specific error scenarios gracefully.

### Advanced Features:
- Diamond inheritance is used with veterinarian classes (`Veterinar`, `VeterinarChirurg`, `VeterinarDermatolog`, `VeterinarSpecializat`), showcasing how to address potential issues with multiple inheritance in C++.
- Dynamic casting, static methods, and virtual functions are employed across various classes to demonstrate advanced OOP concepts and C++ features.

### Usage:
The main function illustrates the creation and manipulation of objects from these classes, including dynamic memory management, exception handling, and polymorphism in action through function calls and interactions between objects.

This project is a testament to the capabilities of OOP in modeling complex systems and provides a solid foundation for further exploration and expansion.

### Business Logic:
- Calculates costs and revenues to determine the zoo's financial health.
- Manages employee details, including contracts, salaries, and roles.
- Enhances customer interaction with dynamic ticket pricing and tracking.

This example showcases how to build a comprehensive system using advanced OOP concepts, providing a robust framework for managing a zoo's operational, financial, and personnel aspects.
