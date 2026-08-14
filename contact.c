#include <stdio.h>
#include "contact.h"
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include <ctype.h>

void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    // Sort contacts based on the chosen criteria

    if (addressBook->contactCount == 0)
    {
        printf("No contacts available.\n");
        return;
    }

    printf("Contact details available-\n-------------------------------------------------------------\n");
    printf("sr No.\t Name : \tPhone No:\tEmail Id: \n-------------------------------------------------------------\n");
   for(int i = 0; i < addressBook->contactCount; i++)
     {
             int length = strlen(addressBook->contacts[i].name);
             if(length > 7)
             {
                   printf("%d\t%s\t%s\t%s\n", i + 1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
             }
             else
             {
                     printf("%d\t%s\t\t%s\t%s\n",i + 1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
			 }
 		}
    printf("-------------------------------------------------------------\n");
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    
    	exit(EXIT_SUCCESS); // Exit the program
}


  void createContact(AddressBook *addressBook)
{
    // Check if address book is full
    if (addressBook->contactCount >= MAX_CONTACTS)
    {
        printf("\n----------------------------------------\n");
        printf("Address book is full! Cannot add more contacts.\n");
        printf("----------------------------------------\n");
        return;
    }

    Contact cont;
    int validate, checkPh, checkEmail;

    // Take and validate name input
    do {
        printf("\nEnter name: ");
        scanf(" %[^\n]", cont.name);

        int validName = 1;  // Assume name is valid initially
        for (int i = 0; cont.name[i]; i++)
        {
            if (!((tolower(cont.name[i]) >= 'a' && tolower(cont.name[i]) <= 'z') || cont.name[i] == ' '))
            {
                validName = 0;  // Set invalid if character is not a letter or space
                printf("\nInvalid Name. Please enter only alphabetic characters.\n");
                break;
            }
        }
        if (validName) break;  // If name is valid, exit the loop

    } while (1);  // Repeat until a valid name is entered

    // Validate phone number
    do
    {
        checkPh = 0;
        printf("\nEnter phone number (10 digits): ");
        scanf("%s", cont.phone);

        // Check if phone number has exactly 10 digits and contains only numbers
        if (strlen(cont.phone) != 10 || strspn(cont.phone, "0123456789") != 10)
        {
            printf("\nInvalid phone number. Please enter a valid 10-digit number.\n");
            checkPh = 1;
        }
        else
        {
            // Check if phone number already exists in address book
            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (strcmp(cont.phone, addressBook->contacts[i].phone) == 0)
                {
                    printf("\nThe entered phone number already exists!\n");
                    checkPh = 1;
                    break;
                }
            }
        }

    } while (checkPh);  // Repeat until a valid, unique phone number is entered

    // Validate email address
    do
    {
        checkEmail = 0;
        printf("\nEnter email address: ");
        scanf("%s", cont.email);
        int i = 0;
        // Validate email format: Must contain '@' and ".com"
        char *atSign = strchr(cont.email, '@');
        if (atSign && strstr(atSign, ".com"))
        {
            if (*(atSign + 1) != '.')  // Ensure there's no '.' immediately after '@'
            {
                // Check if email already exists in address book
                for (i = 0; i < addressBook->contactCount; i++)
                {
                    if (strcmp(cont.email, addressBook->contacts[i].email) == 0)
                    {
                        printf("\nThe entered email address already exists!\n");
                        checkEmail = 1;
                        break;
                    }
                }
            }
            else
            {
                printf("\nERROR: Invalid email format. Please try again.\n");
                checkEmail = 1;
            }
        }
        else
        {
            printf("\nERROR: Invalid email format. Please include '@' and '.com'.\n");
            checkEmail = 1;
        }

    } while (checkEmail);  // Repeat until a valid, unique email is entered

    // Add contact to address book if all validations pass
    addressBook->contacts[addressBook->contactCount++] = cont;
    printf("\n----------------------------------------\n");
    printf("Contact added successfully!\n");
    printf("----------------------------------------\n");
    return ;
}
  

void searchContact(AddressBook *addressBook)
{
    // Check if there are any contacts in the address book
    if (addressBook->contactCount == 0)
    {
        printf("\n----------------------------------------\n");
        printf("No contacts available for searching.\n");
        printf("----------------------------------------\n");
        return;
    }

    int found = 0;
    char temp[50];
    int option;

    // Prompt the user to choose a search option
    printf("\n========================================\n");
    printf("Search Contact\n");
    printf("----------------------------------------\n");
    printf("Choose your option:\n");
    printf("1. Search by Name\n");
    printf("2. Search by Phone Number\n");
    printf("3. Search by Email ID\n");
    printf("----------------------------------------\n");
    printf("Enter your option: ");
    scanf("%d", &option);

    // Loop until a valid contact is found or an invalid option is entered
    do
    {
        found = 0;

        switch (option)
        {
            case 1:
                // Search by Name
                printf("\nEnter name: ");
                scanf(" %[^\n]s", temp); // Space before %[^\n] prevents newline issues
                printf("\nSearching for contacts...\n");

                for (int i = 0; i < addressBook->contactCount; i++)
                {
                    if (strstr(addressBook->contacts[i].name, temp) != NULL)
                    {
                        printf("\n----------------------------------------\n");
                        printf("Contact found:\n");
                        printf("Name: %s\nPhone No: %s\nEmail ID: %s\n", 
                               addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                        printf("----------------------------------------\n");
                        found = 1;
                    }
                }
                break;

            case 2:
                // Search by Phone Number
                printf("\nEnter phone number: ");
                scanf("%s", temp);
                printf("\nSearching for contacts...\n");

                for (int i = 0; i < addressBook->contactCount; i++)
                {
                    if (strcmp(temp, addressBook->contacts[i].phone) == 0)
                    {
                        printf("\n----------------------------------------\n");
                        printf("Contact found:\n");
                        printf("Name: %s\nPhone No: %s\nEmail ID: %s\n", 
                               addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                        printf("----------------------------------------\n");
                        found = 1;
                    }
                }
                break;

            case 3:
                // Search by Email ID
                printf("\nEnter email ID: ");
                scanf("%s", temp);
                printf("\nSearching for contacts...\n");

                for (int i = 0; i < addressBook->contactCount; i++)
                {
                    if (strcmp(temp, addressBook->contacts[i].email) == 0)
                    {
                        printf("\n----------------------------------------\n");
                        printf("Contact found:\n");
                        printf("Name: %s\nPhone No: %s\nEmail ID: %s\n", 
                               addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                        printf("----------------------------------------\n");
                        found = 1;
                    }
                }
                break;

            default:
                printf("\nInvalid option. Please try again.\n");
                return; // Exit on invalid option
        }

        // If no contact is found, prompt the user again
        if (!found)
        {
            printf("\n----------------------------------------\n");
            printf("Contact not found. Please try again.\n");
            printf("----------------------------------------\n");
        }

    } while (!found); // Continue until a contact is found

    printf("========================================\n\n");
}

void editContact(AddressBook *addressBook)
{
    // Prompt user for the option to edit by name, phone, or email
    printf("Enter by which option you want to Edit : \n");
    printf("1. By Name\n2. By Phone no.\n3. By Email id..\n");

    int option, i, found = 0, count = 0; // Initialize variables for options, loop, and status flags
    printf("Enter Your Option : ");
    scanf("%d", &option);

    switch(option) {
        case 1: {  // Edit by name
            char n_temp[50], n_phone[20];  // Temporary storage for name and phone number input
            printf("Enter the Name : ");
            scanf(" %[^\n]", n_temp);  // Get the name to search for

            // Search for contacts matching the given name (partial matches allowed)
            for(i = 0; i < addressBook->contactCount; i++) {
                if (strstr(addressBook->contacts[i].name, n_temp) != NULL) {
                    found = 1;  // Mark as found if match is detected
                    count++;    // Count the number of matches
                }
            }

            if (count > 1) {  // If multiple contacts are found with similar names
                printf("\nYour Saved Contacts : \n");
                printf("--------------------------------------------------------------\n");
                printf("Name \t\tPhone\t\t\tEmail ID\n");
                printf("--------------------------------------------------------------\n");

                // Display all contacts matching the name
                for(i = 0; i < addressBook->contactCount; i++) {
                    if (strstr(addressBook->contacts[i].name, n_temp) != NULL) {
                        printf("%s\t\t%s\t\t%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    }
                }

                // Ask for the specific phone number to identify the correct contact
                printf("\nEnter the Phone no. : ");
                scanf("%s", n_phone);

                // Search for contact by phone number
                for(i = 0; i < addressBook->contactCount; i++) {
                    if (strstr(addressBook->contacts[i].phone, n_phone) != NULL) {
                        printf("\nContact Found!\n");
                        printf("Name: %s\t\tPhone no.: %s\t\tEmail ID: %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);

                        // Ask the user what field they want to edit (name, phone, or email)
                        int no;
                        printf("Enter What Option You want to Edit : \n");
                        printf("1. By Name\n2. By Phone no.\n3. By Email ID\n");
                        printf("Enter Your Option : ");
                        scanf("%d", &no);

                        // Edit the selected field based on user's choice
                        switch(no) {
                            case 1:
                                printf("Enter the New Name : ");
                                scanf(" %[^\n]", addressBook->contacts[i].name);
                                printf("Name Edited Successfully\n");
                                break;
                            case 2:
                                printf("Enter the New Phone no. : ");
                                scanf("%s", addressBook->contacts[i].phone);
                                printf("Phone no. Edited Successfully\n");
                                break;
                            case 3:
                                printf("Enter the New Email ID : ");
                                scanf("%s", addressBook->contacts[i].email);
                                printf("Email ID Edited Successfully\n");
                                break;
                        }
                        break;
                    }
                }
            } else if (count == 1) {  // If only one contact matches the name
                for(i = 0; i < addressBook->contactCount; i++) {
                    if (strstr(addressBook->contacts[i].name, n_temp) != NULL) {
                        // Update the contact's name
                        printf("Enter New Name : ");
                        scanf(" %[^\n]", addressBook->contacts[i].name);
                        printf("Name Updated Successfully\n");
                        return;
                    }
                }
            } else {  // If no contact is found
                printf("Contact Not Found\n");
            }
            break;
        }

        case 2: {  // Edit by phone number
            char ph_temp[40];  // Temporary storage for phone number
            printf("Enter the Phone no. : ");
            scanf("%s", ph_temp);

            // Search for contact by phone number
            for(i = 0; i < addressBook->contactCount; i++) {
                if (strcmp(addressBook->contacts[i].phone, ph_temp) == 0) {
                    // Update the contact's phone number
                    printf("Enter New Phone no : ");
                    scanf("%s", addressBook->contacts[i].phone);
                    printf("Phone no. Updated Successfully\n");
                    return;
                }
            }
            printf("Contact Not Found\n");
            break;
        }

        case 3: {  // Edit by email ID
            char id_temp[40];  // Temporary storage for email ID
            printf("Enter the Email ID : ");
            scanf("%s", id_temp);

            // Search for contact by email ID
            for(i = 0; i < addressBook->contactCount; i++) {
                if (strcmp(addressBook->contacts[i].email, id_temp) == 0) {
                    // Update the contact's email ID
                    printf("Enter New Email ID : ");
                    scanf("%s", addressBook->contacts[i].email);
                    printf("Email ID Updated Successfully\n");
                    return;
                }
            }
            printf("Contact Not Found\n");
            break;
        }

        default:
            printf("Invalid Option\n");
    }
}

void deleteContact(AddressBook *addressBook)
{
    // Check whether contact is present or not
    if (addressBook->contactCount == 0)
    {
        printf("\n----------------------------------------\n");
        printf("No contacts available to delete.\n");
        printf("----------------------------------------\n");
        return;
    }

    char temp[50];
    int option, matchIndex = -1;
    int matches[100]; // Array to store multiple matched indexes
    int matchCount = 0;

    // Display deletion options
    printf("\n========================================\n");
    printf("Delete Contact\n");
    printf("----------------------------------------\n");
    printf("Choose your option:\n");
    printf("1. Delete by Name\n");
    printf("2. Delete by Phone Number\n");
    printf("3. Delete by Email ID\n");
    printf("----------------------------------------\n");
    printf("Enter your option: ");
    scanf("%d", &option);

    printf("\n----------------------------------------\n");

    switch (option)
    {
        case 1:
            printf("Enter name: ");
            scanf(" %[^\n]", temp);
            printf("\nSearching for contacts...\n");

            // Search for matches by name
            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (strstr(addressBook->contacts[i].name, temp) != NULL)
                {
                    printf("\nName: %s\nPhone No: %s\nEmail ID: %s\n",
                           addressBook->contacts[i].name,
                           addressBook->contacts[i].phone,
                           addressBook->contacts[i].email);
                    matches[matchCount++] = i;
                }
            }

            if (matchCount == 0)
            {
                printf("\nContact not found.\n");
                return;
            }
            else if (matchCount == 1)
            {
                matchIndex = matches[0]; // Only one match, proceed to delete
            }
            else
            {
                // Multiple matches found — prompt for further details
                printf("\nMultiple contacts found. Enter the phone number or email ID to confirm deletion: ");
                char confirmDetail[50];
                scanf("%s", confirmDetail);

                for (int i = 0; i < matchCount; i++)
                {
                    int idx = matches[i];
                    if (strcmp(addressBook->contacts[idx].phone, confirmDetail) == 0 ||
                        strcmp(addressBook->contacts[idx].email, confirmDetail) == 0)
                    {
                        matchIndex = idx;
                        break;
                    }
                }

                if (matchIndex == -1)
                {
                    printf("\nNo matching contact found for the given details.\n");
                    return;
                }
            }
            break;

        case 2:
            printf("Enter phone number: ");
            scanf("%s", temp);
            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (strcmp(temp, addressBook->contacts[i].phone) == 0)
                {
                    matchIndex = i;
                    break;
                }
            }
            break;

        case 3:
            printf("Enter email ID: ");
            scanf("%s", temp);
            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (strcmp(temp, addressBook->contacts[i].email) == 0)
                {
                    matchIndex = i;
                    break;
                }
            }
            break;

        default:
            printf("Invalid option. Please try again.\n");
            return;
    }

    printf("----------------------------------------\n");

    if (matchIndex != -1)
    {
        // Shift contacts to remove the matched one
        for (int j = matchIndex; j < addressBook->contactCount - 1; j++)
        {
            addressBook->contacts[j] = addressBook->contacts[j + 1];
        }
        addressBook->contactCount--;
        printf("\nContact deleted successfully!\n");
    }
    else
    {
        printf("\nContact not found.\n");
    }

    printf("========================================\n\n");
}
