#include <iostream>
#include "PhoneBook.h"
#include <fstream>
#include <string>

int main()
{
	PhoneBook* phonebook = new PhoneBook[1]; 
	size_t size = 0, menu; 

	
	while (true)
	{
		system("cls"); 
		std::cout << "Menu:\n1. Add contact\n2. Print Contacts\n3. Delete contact\n4. Find Contact" << std::endl;
		std::cin >> menu; 
		system("cls");
		switch (menu)
		{
			case 1:
				addContact(phonebook, size); 
				break; 
			case 2: 
				printContacts(phonebook, size);
				system("pause"); 
				break; 
			case 3: 
				deleteContact(phonebook, size); 
				break; 
			case 4:
				findContact(phonebook, size);
				system("pause"); 
			/*case 5: якщо розкоментувати, то програма перестане запускатись через помилку з case3 и case 1 (зв'язок так й не знайшов) 
				try
				{
					saveContacts(phonebook, size, "contacts.txt"); 
					std::cout << "Saving successfully" << std::endl; 
				}
				catch(std::ios_base::failure& e)
				{
					std::cout << "Error: " << e.what() << std::endl; 
				}
				break;*/ 
			case 6: 
				break; 
			default:
				delete[] phonebook;
				return 0; 
				break;
		}
	}


	
}