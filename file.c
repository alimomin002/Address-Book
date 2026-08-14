#include <stdio.h>
#include "file.h"
#include "contact.h"

void saveContactsToFile(AddressBook *addressBook) {
    FILE *fptr_temp = fopen("temp.csv", "w");
    fprintf(fptr_temp, "%d\n", addressBook->contactCount);
    int i;
    for(i = 0; i < addressBook->contactCount; i++) {
        fprintf(fptr_temp, "%s", addressBook->contacts[i].name);
        fprintf(fptr_temp, "%c", ',');
        fprintf(fptr_temp, "%s", addressBook->contacts[i].phone);
        fprintf(fptr_temp, "%c", ',');
        fprintf(fptr_temp, "%s\n", addressBook->contacts[i].email);
    }

    remove("add.csv");
    rename("temp.csv", "add.csv");
    fclose(fptr_temp);
}

void loadContactsFromFile(AddressBook *addressBook) 
{
   // rewind(addressBook->fptr_file);
    fscanf(addressBook->fptr_file, "%d\n", &addressBook->contactCount);
    if (addressBook->contactCount == 0) {
        // printf("No Contact\n");
        return;
    }

    for (int i = 0; i < addressBook->contactCount; i++) {
        fscanf(addressBook->fptr_file, "%[^,]", addressBook->contacts[i].name);
        fseek(addressBook->fptr_file, 1, SEEK_CUR);
        fscanf(addressBook->fptr_file, "%[^,]", addressBook->contacts[i].phone);
        fseek(addressBook->fptr_file, 1, SEEK_CUR);
        fscanf(addressBook->fptr_file, "%[^\n]", addressBook->contacts[i].email);
        fseek(addressBook->fptr_file, 1, SEEK_CUR);
    }
}

int Openfile(AddressBook *addressBook) 
{
    addressBook->fptr_file = fopen("add.csv", "r");
    if (addressBook->fptr_file == NULL) 
    {
        perror("fopen");
        printf("File Not Opened\n");
        return 0;
    }
    return 1;
}

