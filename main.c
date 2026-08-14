#include <stdio.h>
#include "contact.h"

int main()
{
	int choice;
    AddressBook addressBook; // AddressBook object to store contacts

    // Load contacts from a file into the address book structure
    loadContactsFromFile(&addressBook);

    // Open the contact file for reading/writing
    Openfile(&addressBook);

    // Initialize the address book (e.g., setting contact count, allocating memory)
    initialize(&addressBook);
    do {

        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

       int x = scanf("%d", &choice);
      // printf("\n%d", x);
      // printf("		%d", choice);

       	if(x == 0)                    // Get user's menu choice
       	{
       			choice = 7;
		}
      // printf("\n%d", x);
      // printf("		%d\n", choice);
      // break;


        switch (choice) 
        {
            case 1:
                // Call the function to create a new contact
                createContact(&addressBook);
                break;
            case 2:
                // Call the function to search for a contact
                searchContact(&addressBook);
                break;
            case 3:
                // Call the function to edit an existing contact
                editContact(&addressBook);
                break;
            case 4:
                // Call the function to delete an existing contact
                deleteContact(&addressBook);
                break;
            case 5:
                printf("Select sort criteria:\n");
                printf("1. Sort by name\n");
                printf("2. Sort by phone\n");
                printf("3. Sort by email\n");
                printf("Enter your choice: ");
                int sortChoice; 
                scanf("%d", &sortChoice);

                // Call the function to list contacts based on the sort criteria
                listContacts(&addressBook, sortChoice);
                break;
            case 6:
                // Save contacts to the file and exit the application
                printf("Saving and Exiting...\n");
                saveContactsToFile(&addressBook);
                break;
            default:
                // Handle invalid menu choices
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 6); 

    return 0;
}

