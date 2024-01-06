C++Core Programming


1. Memory partition

C++programs are divided into four regions in memory during execution:

Code area: Stores the binary code of the function body, managed by the operating system.

Global area: stores global variables, static variables, and variables.

Stack area: Automatically allocated and released by the compiler, storing function parameter values, local variables, etc.

Heap area: allocated and released by programmers, and reclaimed by the operating system after the program ends if not released.

Dividing allows different regions to store different data, assigning different lifecycles, and enhancing programming flexibility.


1.1 Before running the program

After program compilation, an exe executable program is generated, which is divided into two regions before execution.

Code area: (shared read-only)

Store machine instructions executed by the CPU.

The code area is shared, and the purpose of sharing is to have only one copy of code in memory for programs that are frequently executed.

The code area is read-only, and the reason for making it read-only is to prevent the program from accidentally modifying its instructions.

Global Area: (OS Control)

Global and static variables are stored here.

It also includes constant fields, string constants, and other constants (const, etc.).

The data in this area is released by the operating system after the program ends.


1.2 Program runtime

Stack area:

Automatically allocated and released by the compiler, storing function parameter values, local variables, etc.

Do not return the address of a local variable. The data opened in the stack area is automatically released by the compiler after the function or program ends.

Heap area:

Allocated and released by programmers, or reclaimed by the operating system after the program ends.

In C++, new is mainly used to open up memory in the heap area.


1.3new

Using the new operator in C++to open up data.

The data created by the heap area is manually created and released by the programmer using the delete operator.

Syntax: new data type

The data created using new will return a pointer to the corresponding type of data..


2 citations

2.1 Basic Use

Function: Aligning variables

Syntax: data type&alias=original name; (Both point to the same memory address)

2.2 Precautions

Must be initialized.

After reference initialization, it cannot be changed (i.e.&b=c cannot be executed).

2.3 Using references as function parameters

Function: When passing parameters to a function, the technique of referencing can be used to modify the actual parameters (1. Value passing 2. Address passing (pointer)).

Advantages: It can simplify pointer modification of arguments.

2.4 Referencing as a Function Return Value

Function: The reference can exist as the return value of a function.

Note: Local variable references cannot be returned.

Usage: Function call as lvalue.

2.5 The Essence of Quotations

The reference implemented internally in C++is a pointer constant: int&ref=a; Convert to int * const ref=&a; The pointer cannot be changed, but the value can be changed.

2.6 Constant references

Function: Constant references are mainly used to modify formal parameters and prevent accidental operations.

In the function parameter list, const can be added to modify the parameters to prevent them from changing the arguments.


3 functions

3.1 Default Parameters of Functions

In C++, the parameters in the function's parameter list can have default values.

Syntax: return value type function name (parameter=default value) {}

If a location parameter has a default value, then from this address onwards, from left to right, there must be a default value.

If the function declaration has default values, the function implementation cannot have default parameters.

3.2 Function placeholder parameters

The formal parameter list of C++functions can have a placeholder parameter, which must be filled when calling the function.

Syntax: return value type function name (data type) {}

3.3 Function Overloading

3.3.1 Overview

Function: Same function name to improve reusability.

Function overload satisfies the following conditions:

Under the same scope.

2. The function names are the same.

3. Different function parameter types, number of parameters, or order of parameters.

Note: The return value of a function cannot be used as a condition for function overloading.

3.3.2 Precautions

Referencing as an overload condition.

Function overload and default parameters.


4 categories and objects

The three major characteristics of C++object-oriented programming are encapsulation, inheritance, and polymorphism.

4.1 Packaging

4.1.1 The significance of packaging

1. Take attributes and behaviors as a whole to represent the affairs in life.

2. Set permission restrictions on attributes and behaviors.

Eg:

When designing classes, attributes and behaviors are written together to represent things.

Grammar:

Class name {Access permissions: Properties/Behavior};

Eg:

When designing a class, attributes and permissions can be placed under different permissions for control.

1. Within the public member class, it can be accessed. Outside the class, it can be accessed. Subclasses can be accessed

2. Within the protected member class, access is allowed, but outside the class, access is not allowed. Subclass access is allowed

3. Within the private member class, access is allowed, but outside the class, access is not allowed. Subclass access is not allowed

4.1.2 Differences between struct and class

The only difference between the two in C++is their different access permissions.

1. The default permission for struct is public.

The default permission for class is private.

4.1.3 Set member properties to private

Advantage 1: Setting member properties to private allows for self control of read and write permissions.

Advantage 2: For write permissions, we can check the validity of the data.

4.2 Object initialization and cleaning

4.2.1 Constructors and Destructors

The initialization and cleaning of objects are also two very important security issues.

The consequences of using an object or variable without an initial state are unknown.

Similarly, using an object or variable without timely cleaning can also cause certain security issues.

C++solves the above problem by using constructors and destructors, which will be automatically called by the compiler to complete object initialization and cleaning tasks.

If we don't provide constructors and destructors, the compiler will provide empty implementation constructors and destructors.

Constructor: The main function is to assign values to the member properties of an object when creating it, and the constructor is automatically called by the compiler without the need for manual calling.

Destructor function: The main function is to automatically call the system and perform some cleaning tasks before the object is destroyed.

Constructor syntax: class name() {}

1. No return value and no void written.

2. The function name is the same as the class name.

3. Constructors can have parameters, so overloading can occur.

4. The program will automatically call the construct when calling the object, without the need for manual calling, and it will only be called once.

Destructor syntax:~Class name() {}

1. No return value and no void written.

2. The function name is the same as the class name, with the symbol~added before the name.

3. Constructors cannot have parameters, so overloading cannot occur.

4. The program will automatically call destruct before the object is destroyed, without the need for manual calls, and it will only be called once.

4.2.2 Classification and invocation of constructors

According to parameters, it can be divided into parameterized construction and non parameterized construction.

Classified by type: regular construction and copy construction.

Divide the calling methods into: bracket method, display method, and implicit conversion method.

4.2.3 When to call the copy constructor

There are three ways to call copy constructors in C++:

1. Use an already created object to initialize a new one.

2. The method of passing values to function parameters.

3. Return local variables as values.

4.2.4 Rules for calling constructors

By default, the C++compiler adds at least 3 functions to a class.

1. Default parameterless construction

2. Default Destructor

3. Default copy function

The calling rules are as follows:

1. User defined parameterized constructors, C++no longer provides parameterized constructors, but provides default copy constructors.

2. User defined copy constructors, C++no longer provides other constructors.

4.2.5 Deep and Light Copy (Classic Interview Questions)

Shallow copy: A simple copy operation, but the problem with shallow copy is that the memory in the heap area will be repeatedly released, which needs to be solved by using deep copy.

Deep copy: reapply for space in the heap area and perform a copy operation.

4.2.6 Initialize List

C++provides an initialization list for initializing properties

Syntax: Constructor(): Attribute Value 1 (Value 1), Attribute Value 2 (Value 2), Attribute Value 3 (Value 3) {}

4.2.7 Object Members

Members in a class in C++can be objects of another class, known as member objects.

The construction and deconstruction order of class a and its object member class b is: the objects of the object member class are created first, and the destruction order is the opposite.

4.2.8 Static Members

Adding static before a member variable is called a static member.

1. Static member variables:

a. All objects share one copy of data.

b. Allocate memory during the compilation phase.

c. In class declaration, out of class initialization.

2. Static member functions

a. All objects share a function.

b. Static member functions can only access static member variables.

Static member variables can be accessed through objects or class names, and they also have corresponding access permissions.

Static member functions can be accessed through objects or class names, and they also have corresponding access permissions.

4.3C++Object Model and This Pointer

4.3.1 Separate storage of member variables and member functions

In C++, member variables and member functions of a class are stored separately.

Only non-static member variables belong to objects of the class.

The C++compiler allocates a byte of memory space to each empty object to distinguish the location of the memory occupied by the empty object, so that each empty object has a unique memory address.

Static member variables do not belong to any object and do not occupy the object's memory space. Member functions are also unique and do not occupy the object's memory space.

4.3.2 This pointer

From the above, we know that in C++, class member variables and member functions are stored separately.

Each non-static member function will only give birth to one function instance, which means that multiple objects of the same type will share the same block of code. How can this block of code distinguish which object calls itself?

C++solves the above problem by providing special object pointers, this pointers. The this pointer only wants the object to which the member function being called belongs.

This pointer is a type of pointer that is implied within each non-static member function and does not need to be defined. It can be used directly.

The purpose of this pointer is:

1. Distinguish when the type of participating member variable has duplicate names.

2. In non-static member functions of a class, return * this can be used to return the object itself;

4.3.3 null pointer access to member functions

C++hollow pointers can also call member functions, but it is also important to note whether the this pointer is used. If the this pointer is used, it should be checked to ensure the robustness of the code.

4.3.4 const modifying member functions

Constant function:

After adding const to the member function, we call it a constant function.

2. Member properties cannot be modified within long functions.

3. When declaring member properties, the keyword mutable can also be modified in regular functions.

Long object:

1. Add const before declaring an object to call it a regular object.

2. Regular objects can only call regular functions.

Adding const after a member function essentially modifies the this pointer, making its value immutable.
4.4 Friendship

In life, your home has a living room and a bedroom. The former allows all guests to enter, but the latter is private and only you can enter.

But you can let your friends in.

In programs, some private properties also need to be accessed by special functions or classes outside of the class, which requires friends.

Friend allows a function or class to access private members in another class, with the keyword: friend.

4.4.1 Making Friends of Global Functions

4.4.2 Friend class

4.4.3 Member functions are used as friend PS. In this case, in order to ensure that calls to two classes can be compiled syntactically, the relevant function code can be defined outside of the class.

4.5 Operator Overloading

Redefine existing operators and give them another function to adapt to different data types.

4.5.1 Plus sign

After overloading the operator, it can also be extended through function overloading.

4.5.2 Left shift operator overload (<<)

Function: It can output custom data types and generally does not overload the left shift operator with member functions.

4.5.3 Incremental Operator Overloading (++)

4.5.4 Assignment Operator Overloading

The C++compiler has added at least 4 functions to a class

1. Default parameterless construction

2. Default Destructor

3. Default copy function

4. The assignment operator operator+copies the attribute.

If there are attributes pointing to the heap area in the class, performing assignment operations can also cause depth copying problems.

Solve shallow copy problems by overloading assignment operators.

4.5.5 Overloading of relational operators
4.5.6 Function Call Operator Overloading

1. The function call operator () can also be overloaded.

2. Due to the fact that the method used after overloading is very similar to function calls, it becomes a generic function.

3. The imitation function has no fixed writing method and is very flexible.

4.6 Inheritance

4.6.1 Basic Grammar

Class subclass: Inheritance method parent class{


}

Subclass, also known as derived class, and parent class, also known as base class.

4.6.2 Inheritance method

1. Public inheritance

2. Protection of inheritance

3. Private inheritance

The private members of the parent class cannot be accessed regardless of the inheritance method of the subclass.

Public inheritance keeps the properties of members inherited from the parent class unchanged; Protect inheritance to make public members inherited by subclasses protected members; Private inheritance makes all members inherited by subclasses private.

Unable to access outside of the protection permission class.

4.6.3 Object Model in Inheritance

Private members in the parent class are only hidden during the inheritance process, but they will still inherit, meaning that all non static member properties in the parent class will be inherited by the subclass.

Using developer command prompt tools to view object models:

1. Jump to the folder where the CPP file is located, cd/

2. View command: cl/d1 reportSingleClassLayout class name file name

4.6.4 Construction and Deconstruction Order in Inheritance

When generating a subclass object, the parent class object needs to be constructed first, and then the subclass object needs to be constructed. When deconstructing, the subclass object needs to be deconstructed first, and then the parent class object needs to be deconstructed.

4.6.5 Inheritance · How to handle members with the same name

1. Access the member of the subclass with the same name directly.

2. To access a member of the parent class with the same name, a scope needs to be added.

e. G. 'Son s; s. Base:: a‘

If a member function with the same name as the parent class appears in a subclass, the same name member of the subclass will cause all members with the same name in the parent class to be hidden.

4.6.6 Handling of Inheriting Static Members with the Same Name

1. Access the member of the subclass with the same name directly.

2. To access a member of the parent class with the same name, a scope needs to be added.

4.6.7 Multiple Inheritance Grammar

C++allows a class to inherit multiple classes

Syntax: class subclass: inheritance method parent class 1, inheritance method parent class 2, inheritance method parent class 3

Multiple inheritance may cause the appearance of members with the same name in the parent class, which needs to be distinguished by adding a scope.

It is not recommended to use multiple inheritance in actual development of C++.

4.6.8 Diamond Inheritance

Concept:

1. Two derived classes inherit from the same base class.

2. A certain class inherits both derived classes simultaneously.

3. It is called diamond inheritance or diamond inheritance.

The data from the original base class inherits two copies, but only one copy is needed.

The use of virtual inheritance can solve the problem of diamond inheritance, which involves adding the 'virtual' keyword before inheritance to become virtual inheritance. The base class is called a virtual base class.

Virtual inheritance uses a virtual base class pointer vbptr to point to the virtual base class table vbtable, which records the offsets of different members, resulting in only one duplicate member.

4.7 Polymorphism

4.7.1 Basic concepts

1. Static polymorphism: Function overload and operator overload belong to static polymorphism, reusing function names.

2. Dynamic polymorphism: Derived classes and virtual functions implement runtime polymorphism

The difference between the two:

1. Static polymorphic function address early binding - determine function address during compilation phase

2. Dynamic polymorphism of function address late binding - determining function address during runtime

Dynamic polymorphism satisfies the condition

*1. There is an inheritance relationship

*2. Subclass rewrites parent class virtual function

*Rewrite: The return value type, function name, and parameter list of the function must be exactly the same.

*The virtual function of subclass rewritten virtual functions can be written or not written

Principle:

*When there is a virtual function in the parent class, the object of the class will generate a virtual function (table) pointer vfptr (4B), which points to the virtual function table vftable, which records the virtual function.

*When a subclass does not rewrite a virtual function, it inherits the virtual function pointer. After rewriting the virtual function, the virtual function table of the subclass is overwritten, and the pointer points to the virtual function address of the subclass. When the pointer or reference of the parent class points to the subclass object, polymorphism occurs.

The advantages of polymorphism:

1. Clear code organization structure

2. Strong readability

3. Beneficial for expansion and maintenance in the early and later stages

4.7.3 Pure Virtual Functions and Abstract Classes

In polymorphism, the implementation of virtual functions in the parent class is usually meaningless, mainly by calling the content rewritten by the subclass, so virtual functions can be changed to pure virtual functions.

Syntax: virtual returns value type function name (parameter list)=0;

When there is a pure virtual function in a class, it can be called an abstract class.

The characteristics of abstract classes:

1. Unable to instantiate

2. Subclasses must override pure virtual functions in abstract classes, otherwise they also belong to abstract classes.

4.7.5 Virtual and Pure Virtual Structures

When using polymorphism, if a property in a subclass is opened to the heap, the parent class pointer cannot call the destructor code of the subclass when released

Solution: Change the destructor in the parent class to virtual or pure virtual destruction

Commonalities between virtual and pure virtual structures:

1. Can solve the problem of releasing subclass objects from parent class pointers

2. Both require specific function implementations

Difference:

If it is a pure virtual destructor, the class belongs to an abstract class and cannot be instantiated, but pure virtual destructors sometimes require both declaration and implementation.

5 file operations

The data generated during program runtime belongs to temporary data, which will be released once the program finishes running. Data can be persisted through files, and file operations in C++need to include header files<fstream>

There are two types of files:

1. Text file - The file is stored in ASCII format as text on the computer

2. Binary Files - Files are stored in binary form as text on a computer, and users generally cannot directly understand them

There are three main categories of operating files:

1. of stream: write operation

2. ifstream: read operation

3. fstream: read and write operations

5.1 Text files

5.1.1 Writing Files

The steps for writing a file are as follows:

1. Include header file: # include<fstream>

2. Create a stream object: ofstream of s;

3. Open file: ofs. open ("file path", opening method);

4. Write data: of s<<"written data";

5. Close file: of s. close();

File opening method:

Explanation of opening method

Ios:: in Open file for reading

Ios:: out Open file for writing

Ios:: ate Initial position: End of file

IOS:: App append method for writing files

Ios:: trunk If the file exists, delete it first and then create it again

Los:: binary binary mode

Note: The file opening method can be used in conjunction with the | operator

For example, writing files in binary format ios:: binary | ios:: out

5.1.2 Reading Files

The steps to read a file are as follows:

1. Include header file: # include<fstream>

2. Create a stream object: ifstream ifs;

3. Open the file and check if it was successfully opened: ifs. open ("file path", opening method);

4. Data reading: Four ways to read

5. Close file: ifs. close();

5.2 Binary files

5.2.1 Writing

Call the write function: ostream&write (const char * buffer, int len);

The character pointer buffer points to a storage space in memory, where len is the number of bytes.

5.2.2 Reading

Call the read function: istream&read (const char * buffer, int len);

The character pointer buffer points to a storage space in memory, where len is the number of bytes.
