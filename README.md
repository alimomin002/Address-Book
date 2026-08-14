# 📒 Address Book Management System in C

A simple **Address Book Management System** developed in **C programming**. This project allows users to create, search, edit, delete, and list contacts through a menu-driven command-line interface.

Contact information is stored persistently in a **CSV file**, so the data can be saved and loaded between program executions.

## 📌 Features

* ➕ **Create Contact**

  * Add a new contact with name, phone number, and email.
  * Validates the name to allow alphabetic characters and spaces.
  * Validates phone numbers to contain exactly 10 digits.
  * Prevents duplicate phone numbers.
  * Validates email addresses.
  * Prevents duplicate email addresses.

* 🔍 **Search Contact**

  * Search contacts by:

    * Name
    * Phone number
    * Email ID
  * Supports partial name searching.

* ✏️ **Edit Contact**

  * Edit contact details using:

    * Name
    * Phone number
    * Email ID
  * Handles multiple contacts with similar names.

* 🗑️ **Delete Contact**

  * Delete contacts using:

    * Name
    * Phone number
    * Email ID
  * Provides additional identification when multiple contacts have the same name.

* 📋 **List Contacts**

  * Displays all saved contacts.
  * Provides options to select sorting criteria.

* 💾 **File Storage**

  * Contact data is stored in `add.csv`.
  * Existing contacts are loaded when the program starts.
  * Updated contact information is saved when the program exits.

## 🛠️ Technologies Used

* **Language:** C
* **Concepts Used:**

  * Structures
  * Arrays
  * Functions
  * Pointers
  * File Handling
  * String Manipulation
  * Input Validation
  * Searching
  * Data Management
  * Menu-driven programming

## 📂 Project Structure

A typical project structure is:

```text
AddressBook/
│
├── main.c
├── contact.c
├── contact.h
├── file.c
├── file.h
├── add.csv
└── README.md
```

### File Description

| File        | Description                                                                          |
| ----------- | ------------------------------------------------------------------------------------ |
| `main.c`    | Contains the main menu and controls the program flow.                                |
| `contact.c` | Contains functions for creating, searching, editing, deleting, and listing contacts. |
| `contact.h` | Contains contact and address book declarations and function prototypes.              |
| `file.c`    | Handles loading and saving contacts to the CSV file.                                 |
| `file.h`    | Contains file-handling function declarations.                                        |
| `add.csv`   | Stores contact information permanently.                                              |
| `README.md` | Project documentation.                                                               |

## 📊 Contact Data Format

Contacts are stored in CSV format:

```text
Name,Phone,Email
```

Example:

```text
Rahul,9876543210,rahul@gmail.com
Priya,9123456780,priya@gmail.com
Amit,9988776655,amit@gmail.com
```

The program also stores the number of contacts at the beginning of the file.

## 🚀 How to Run

### 1. Clone the Repository

```bash
git clone https://github.com/your-username/your-repository-name.git
```

### 2. Navigate to the Project Directory

```bash
cd your-repository-name
```

### 3. Compile the Program

Using GCC:

```bash
gcc main.c contact.c file.c -o addressbook
```

### 4. Run the Program

On Linux/macOS:

```bash
./addressbook
```

On Windows:

```bash
addressbook.exe
```

## 🖥️ Program Menu

When the program starts, the following menu is displayed:

```text
Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Exit

Enter your choice:
```

### Create Contact

Select option `1` and enter:

```text
Name
Phone Number
Email Address
```

The program validates the entered information before adding the contact.

### Search Contact

Select option `2`:

```text
Search Contact
--------------------
1. Search by Name
2. Search by Phone Number
3. Search by Email ID
```

### Edit Contact

Select option `3` to modify an existing contact.

### Delete Contact

Select option `4` to remove a contact from the address book.

### List Contacts

Select option `5` to display all stored contacts.

### Exit

Select option `6` to save the contacts to `add.csv` and exit the application.

## 💡 Concepts Demonstrated

This project demonstrates several important C programming concepts:

### Structures

Contacts and the address book are represented using structures.

```c
typedef struct
{
    char name[50];
    char phone[20];
    char email[50];
} Contact;
```

### File Handling

The project uses C file-handling functions such as:

```c
fopen()
fscanf()
fprintf()
fclose()
remove()
rename()
```

### String Functions

The project uses functions including:

```c
strlen()
strcmp()
strstr()
strchr()
strspn()
```

### Dynamic Menu Operations

The program uses a `switch` statement to perform different operations based on the user's choice.

## ⚠️ Current Limitations

This project is designed as a learning project and has some limitations:

* Email validation currently focuses on basic `@` and `.com` checks.
* Phone numbers are limited to 10 digits.
* The application uses a fixed maximum number of contacts.
* Input handling uses `scanf()`, so some edge cases involving invalid input may require additional handling.
* Sorting options are displayed, but the current `listContacts()` implementation does not actually perform sorting.

## 🔮 Future Improvements

Possible improvements include:

* [ ] Implement actual sorting by name, phone, and email.
* [ ] Improve input validation.
* [ ] Support international phone numbers.
* [ ] Improve email validation.
* [ ] Add case-insensitive searching.
* [ ] Add confirmation before deleting a contact.
* [ ] Improve CSV parsing and handling of special characters.
* [ ] Add a Makefile for easier compilation.
* [ ] Improve error handling for file operations.
* [ ] Add unit tests.
* [ ] Add a graphical user interface in a future version.

## 🎯 Learning Objective

The main objective of this project is to practice **C programming fundamentals** by developing a practical application involving:

* Structures
* Functions
* Pointers
* Arrays
* File handling
* String manipulation
* Searching
* Input validation
* Modular programming

## 👨‍💻 Author

**Your Name**

GitHub: `https://github.com/your-username`

## 📄 License

This project is available for educational and learning purposes.
