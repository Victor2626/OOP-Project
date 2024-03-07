# Zoo Project ~ OOP Project
## Project Description:
In this project, we have created an application that manages a database of a zoo, using fundamental object-oriented programming techniques.

This project contains 4 classes: Animal, Show, Ticket, and Cost.

### We also used composition, thus the Show has a vector with Animal type objects (representing a list of animals participating in a show).

#### Class "Animal":
- Setting/getting the type of the animal
- Setting/getting the location of the animal
- Setting/getting the name of the animal
- Overriding the display operator for displaying information about the animal
- Overriding the move operator so an object can take over characteristics from another object, deallocating memory for the latter

#### Class "Ticket":
- Setting/getting the price of the ticket
- Setting/getting the type of the ticket
- Overriding the display operator for displaying information about the ticket

#### Class "Show":
- Setting/getting the maximum number of spectators of the show
- Setting/getting the start time of the show
- Setting/getting the number of animals of the show
- Overriding the display operator for displaying information about the show

#### Class "Cost":
- Setting/getting the cost of the animals' food
- Setting/getting the cost of employee salaries
- Setting/getting the cost of rent
- Setting/getting the cost of maintenance
- Overriding the display operator for displaying information about the cost

### Business functions:
- Calculating the zoo's profit
- Calculating the number of employees and the total salary they receive

Of course, we can create new objects using the constructor, but also copy them, using the copy constructor and assignment operator. The memory allocated for attributes that are string types can be managed with the help of constructors and destructors.
