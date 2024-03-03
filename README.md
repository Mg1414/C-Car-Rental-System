# C-Car-Rental-System
C++ OOPS Assignment , CS253 Course, Mayank Gupta, 220638
How to use:

To run car rental system type ./a.out in the terminal.
If you want to edit the .cpp file, type g++ as.cpp in the terminal after editing to compile.

If you see a numbered list on the terminal, enter the number of the functionality you want to use.
1. Show the available cars
2. View your rented cars
3. View customer profile
4. Request to rent a car
5. Request to return a car
6. View your fine
7. Logout
8. Enter your choice:
  
 Follow the instructions you get on the terminal.

 NOTE:
 i) When a customer/employee rents a car, the due date is set to 30 days from the day on which the car was rented(this is the current date. If it is rented on 3rd march then the due date will be 2nd april). If you want to test the fine showing functionality, manually edit the cars.txt file and change the due date. You can change it to feburary(this will ensure that the fine is >0).
 ii) The date is stored as yyyy-mm-dd
 iii)rating: A+,A implies max 4 cars rentable
 iv) fine of 20 rs/day after due date
 v) cars.txt has the data in the format, model,cond,price,availability,duedate
 managers.txt
 employee.txt
 customers.txt
 vi)
 class user has class manager and class Customer_Employee.
 class Customer_Employee has class Customer and class Employee
