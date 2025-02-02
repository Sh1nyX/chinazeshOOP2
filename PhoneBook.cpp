#include "PhoneBook.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

PhoneBook createContact()
{
	std::string name, surname, patronymic, contactinfo;
	size_t homenumber, worknumber, phonenumber;

	std::cout << "Input name: "; 
	std::cin >> name; 
	std::cout << "Input surname: "; 
	std::cin >> surname; 
	std::cout << "Input patronymic: "; 
	std::cin >> patronymic;
	std::cout << "Input homenumber: "; 
	std::cin >> homenumber; 
	std::cout << "Input worknumber: "; 
	std::cin >> worknumber; 
	std::cout << "Input phonenumber: "; 
	std::cin >> phonenumber; 
	std::cout << "Input contact info: ";
	std::cin.ignore();
	std::getline(std::cin, contactinfo); 

	return PhoneBook(name, surname, patronymic, homenumber, worknumber, phonenumber, contactinfo);

}

void addContact(PhoneBook*& phonebook, size_t& size)
{
	PhoneBook newContact = createContact(); 

	PhoneBook* newPhonebook = new PhoneBook[size + 1]; 

	for (size_t i = 0; i < size; ++i)
	{
		newPhonebook[i] = phonebook[i];
	}

	newPhonebook[size] = newContact;

	delete[] phonebook; 
	phonebook = nullptr; 

	phonebook = newPhonebook; 

	++size; 
}

void printContacts(PhoneBook*& phonebook, size_t& size)
{
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << "Name: " << phonebook[i].getName(); 
		std::cout << "\nSurname: " << phonebook[i].getSurname();
		std::cout << "\nPatronymic: " << phonebook[i].getPatronymic();
		std::cout << "\nHomenumber: " << phonebook[i].getHomenumber();
		std::cout << "\nWorknumber: " << phonebook[i].getWorknumber();
		std::cout << "\nPhonenumber: " << phonebook[i].getPhonenumber();
		std::cout << "\nContact info: " << phonebook[i].getContactinfo() << std::endl; 
		std::cout << std::endl;
	}
	
}

void deleteContact(PhoneBook*& phonebook, size_t& size)
{
	size_t index; 
	try
	{
		std::cout << "Input number of contact u wanna delete: ";
		std::cin >> index;
		if (index < 1 || index > size)
			throw std::out_of_range("Invalid index");

		if (size == 0)
			throw std::logic_error("No elements in array"); 

		if (size == 1)
		{
			delete[] phonebook; 
			phonebook = nullptr; 
			size = 0; 
			return; 
		}

		PhoneBook* newPhonebook = new PhoneBook[size - 1];
		for (size_t i = 0, j = 0; i < size; ++i)
		{
			if (i == index - 1)
				++i; 
			newPhonebook[j] = phonebook[i];
			++j; 
		}

		delete[] phonebook;
		phonebook = nullptr;

		phonebook = newPhonebook;

		--size;
	}
	catch (std::out_of_range e) {
		std::cout << e.what() << std::endl; 
	}
}

void findContact(PhoneBook*& phonebook, size_t& size)
{
	bool found = false; 
	std::string name, surname, patronymic; 
	std::cout << "Input name: ";
	std::cin >> name;
	std::cout << "Input surname: ";
	std::cin >> surname;
	std::cout << "Input patronymic: ";
	std::cin >> patronymic;
	
	for (int i = 0; i < size; ++i)
	{
		if (phonebook[i].getName() == name && phonebook[i].getSurname() == surname && phonebook[i].getPatronymic() == patronymic)
		{
			printFoundContact(phonebook, i);
			found = true; 
			break; 
		}
	}
	if (found == false)
		std::cout << "Contact is not found" << std::endl;
	
}

void printFoundContact(PhoneBook*& phonebook, size_t index)
{
	system("cls");
	std::cout << "Name: " << phonebook[index].getName();
	std::cout << "\nSurname: " << phonebook[index].getSurname();
	std::cout << "\nPatronymic: " << phonebook[index].getPatronymic();
	std::cout << "\nHomenumber: " << phonebook[index].getHomenumber();
	std::cout << "\nWorknumber: " << phonebook[index].getWorknumber();
	std::cout << "\nPhonenumber: " << phonebook[index].getPhonenumber();
	std::cout << "\nContact info: " << phonebook[index].getContactinfo() << std::endl;
	std::cout << std::endl;
}

void saveContacts(PhoneBook* phonebook, size_t size, const std::string& filename)
{
	std::ofstream outputFile(filename, std::ios::out); 
	if (!outputFile)
		throw std::ios_base::failure("Error while opening file for writing"); 

	for (size_t i = 0; i < size; ++i)
	{
		outputFile << phonebook[i].getName() << "\n"
			<< phonebook[i].getSurname() << "\n"
			<< phonebook[i].getPatronymic() << "\n"
			<< std::to_string(phonebook[i].getHomenumber()) << "\n"
			<< std::to_string(phonebook[i].getWorknumber()) << "\n"
			<< std::to_string(phonebook[i].getPhonenumber()) << "\n"
			<< phonebook[i].getContactinfo() << "\n";
	}

	outputFile.close();
}
