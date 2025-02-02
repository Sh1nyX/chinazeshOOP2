#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <iostream>
#include <string>

class PhoneBook
{
	std::string m_name; 
	std::string m_surname; 
	std::string m_patronymic; 
	size_t m_homenumber; 
	size_t m_worknumber; 
	size_t m_phonenumber;
	std::string m_contactinfo; 

public: 
	
	PhoneBook() : m_name{ "Null" }
		, m_surname{"Null"}
		, m_patronymic{ "Null" }
		, m_homenumber{ 0 }
	    , m_worknumber{ 0 }
		, m_phonenumber{ 0 }
		, m_contactinfo{ "Null" }
	{}

	PhoneBook(std::string name, std::string surname, std::string patrinymic, size_t homenum, size_t worknum, size_t phonenum, std::string cinfo) :
		m_name{ name }
		, m_surname { surname }
		, m_patronymic { patrinymic }
		, m_homenumber { homenum }
		, m_worknumber { worknum }
		, m_phonenumber { phonenum }
		, m_contactinfo { cinfo }
	{}

	~PhoneBook() {}

	void setName(std::string name) {
		m_name = name; 
	}

	std::string& getName(){
		return m_name; 
	}

	void setSurname(std::string surname) {
		m_surname = surname;
	}

	std::string& getSurname(){
		return m_surname;
	}

	void setPatronymic(std::string patronymic) {
		m_patronymic = patronymic; 
	}

	std::string& getPatronymic(){
		return m_patronymic; 
	}

	void setHomenumber(size_t homenum) {
		m_homenumber = homenum;
	}

	size_t getHomenumber() {
		return m_homenumber; 
	}

	void setWorknumber(size_t worknum) {
		m_worknumber = worknum;
	}

	size_t getWorknumber() {
		return m_worknumber;
	}


	void setPhonenumber(size_t phonenum) {
		m_phonenumber = phonenum;
	}

	size_t getPhonenumber() {
		return m_phonenumber;
	}

	void setContactinfo(std::string cinfo) {
		m_contactinfo = cinfo; 
	}

	std::string getContactinfo(){
		return m_contactinfo; 
	}

	
};

PhoneBook createContact();

void addContact(PhoneBook*& phonebook, size_t& size); 

void printContacts(PhoneBook*& phonebook, size_t& size); 

void deleteContact(PhoneBook*& phonebook, size_t& size); 

void findContact(PhoneBook*& phonebook, size_t& size); 

void printFoundContact(PhoneBook*& phonebook, size_t index); 

void saveContacts(const PhoneBook* phonebook, size_t size, const std::string& filename);

#endif
