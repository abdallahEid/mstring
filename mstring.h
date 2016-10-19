/*
 * 		mstring.h
 *      Author: Youssef Khaled , Kareem Waleed , Abdallah Eid
 */

#ifndef MSTING_H_
#define MSTING_H_

#include <iostream>
#include <stdexcept>
using namespace std;

class mstring {

private:
	char *str;
	int siz, cap;
public:
	//long int strlen(const char * s)
	long int power(int);
//constructors
	mstring();
	mstring(const mstring &str);
	mstring(const char *s);
	~mstring();
//operators
	friend ostream& operator<<(ostream& os, const mstring& str);
	friend istream& operator>>(istream& is, mstring& str);
	void getline(istream &is);
	mstring& operator=(const mstring& str);
	mstring& operator=(const char* s);
	mstring& operator=(char c);
	friend mstring operator +(const mstring &str1, const mstring &str2);
	mstring& operator+=(const mstring& str);
	mstring& operator+=(const char* s);
	mstring& operator+=(char c);
	bool operator <(const mstring& other);
	bool operator >(const mstring& other);
	bool operator ==(const mstring& other);
	bool operator >=(const mstring &other);
	bool operator <=(const mstring& other);
	char& operator [](int index);
//functions
	int size() const;
	int length() const;
	void resize(int t);
	void resize(int t, char c);
	int capacity() const;
	void clear();
	bool empty();
	void shrink_to_fit(); //make the capacity == size
	char& at(int index) throw (out_of_range); //get the element in the index
	char back(); //get the last char
	char front(); // get the first char
	void push_back(char c);
	mstring& insert(int pos, const mstring& str) throw (out_of_range); //insert str
	mstring& insert(int pos, const char* s) throw (out_of_range);
	mstring& insert(int pos, int n, char c) throw (out_of_range); //insert char to str
	mstring& append(const mstring& str);
	mstring& append(const char* s);
	mstring& append(int n, char c);
	int find(const mstring& str, int pos) const; //find string
	int find(const char* s, int pos) const; //find cstring
	int find(char c, int pos) const; //find char
	mstring& erase(int pos, int len) throw (out_of_range);
	void swap(mstring& str); //swap with other str
	void pop_back(); //delete last char
	int compare(const mstring & other);
	void toupper();
	void tolower();
	mstring substr(int pos, int len) const;
	mstring& replace(int pos, int len, const mstring& str);
	void reverse();
	void reversewords();
	int countwords();
	void sortwords();
	void display();
};
#endif /* MSTING_H_ */
