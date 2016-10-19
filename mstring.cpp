/*
 * 		mstring.cpp
 *      Author: Youssef Khaled , Kareem Waleed , Abdallah Eid
 */

#include "mstring.h"

long int strlen(const char * s) {
	long int siz = 0;
	long int it = 0;
	while (s[it] != '\0') {
		siz++;
		it++;
	}
	return siz;
}

long int mstring::power(int number) {
	long int temp = 1;
	while (temp <= number)
		temp *= 2;
	return temp;
}

//--------------------constructors----------------------------------------------------

mstring::mstring() {
	siz = 0;
	cap = 2;
	str = new char[cap];

}

mstring::mstring(const mstring &str) {
	cap = power(str.siz);
	siz = str.siz;
	this->str = new char[cap];
	for (int i = 0; i < siz; i++)
		this->str[i] = str.str[i];
	this->str[siz] = '\0';
}

mstring::mstring(const char *s) {
	siz = strlen(s);
	cap = power(siz);
	str = new char[cap];
	for (int i = 0; i <= siz; i++)
		str[i] = s[i];
}

mstring::~mstring() {
	delete[] str;
}

//---------------------operators------------------------------------------------------

ostream& operator<<(ostream& os, const mstring& str) {
	os << str.str;
	return os;
}

istream& operator>>(istream& is, mstring& str) {

	str.clear();
	char c;
	while (is.get(c) && c != '\n') {
		if (c == ' ' && str.empty())
			continue;
		else if (c == ' ' && !str.empty())
			break;
		str += c;
	}

	return is;
}
void mstring::getline(istream & is) {

	this->clear();
	char c;
	while (is.get(c) && c != '\n') {
		if (c == '\n')
			break;
		else
			*(this) += c;

	}
}

mstring& mstring::operator=(char c) {
	delete[] str;
	siz = 1;
	cap = 2;
	str = new char[cap];
	str[0] = c;
	str[1] = '\0';
	return *this;
}

mstring& mstring::operator =(const mstring & str) {

	delete[] this->str;
	cap = power(str.siz);
	siz = str.siz;
	this->str = new char[cap];
	for (int i = 0; i < siz; i++)
		this->str[i] = str.str[i];
	this->str[siz] = '\0';
	return *this;
}

mstring& mstring::operator =(const char *s) {
	delete[] str;
	siz = strlen(s);
	cap = power(siz);
	str = new char[cap];
	for (int i = 0; i <= siz; i++)
		str[i] = s[i];

	return *this;
}

mstring& mstring::operator+=(const mstring& str) {
	long long int temp = siz + str.siz;
	int cnt = 0;
	if (temp < cap) {
		for (int i = siz; i < temp; i++)
			this->str[i] = str.str[cnt++];
		this->str[temp] = '\0';
		siz = temp;
		cap = power(siz);
		return *this;
	}
	cap = power(temp);
	char* ptemp = new char[temp];
	for (int i = 0; i < siz; i++) {
		ptemp[i] = this->str[i];
	}
	for (int i = siz; i < temp; i++) {
		ptemp[i] = str.str[cnt++];
	}
	delete[] this->str;
	this->str = new char[cap];
	for (int i = 0; i < temp; i++) {
		this->str[i] = ptemp[i];
	}
	this->str[temp] = '\0';
	siz = temp;
	delete[] ptemp;
	return *this;
}

mstring& mstring::operator +=(const char *s) {
	long long int temp = siz + strlen(s);
	int cnt = 0;
	if (temp < cap) {
		for (int i = siz; i < temp; i++)
			this->str[i] = s[cnt++];
		this->str[temp] = '\0';
		siz = temp;
		cap = power(siz);
		return *this;
	}
	cap = power(temp);
	char* ptemp = new char[temp];
	for (int i = 0; i < siz; i++) {
		ptemp[i] = this->str[i];
	}
	for (int i = siz; i < temp; i++) {
		ptemp[i] = s[cnt++];
	}
	delete[] this->str;
	this->str = new char[cap];
	for (int i = 0; i < temp; i++) {
		this->str[i] = ptemp[i];
	}
	this->str[temp] = '\0';
	siz = temp;
	delete[] ptemp;
	return *this;
}

mstring& mstring::operator +=(char c) {

	if (siz + 1 < cap) {
		str[siz] = c;
		siz++;
		str[siz] = '\0';
	} else {
		char * temp = new char[siz + 1];
		cap = power(siz + 1);
		for (int i = 0; i < siz; i++) {
			temp[i] = str[i];
		}
		temp[siz] = c;
		siz++;
		delete[] str;
		str = new char[cap];
		for (int i = 0; i < siz; i++) {
			str[i] = temp[i];
		}
		str[siz] = '\0';
		delete[] temp;
	}
	return *this;
}

mstring operator +(const mstring &str1, const mstring &str2) {
	mstring temp = "ss";
	delete[] temp.str;
	temp.siz = str1.siz + str2.siz;
	temp.cap = temp.power(temp.siz);
	temp.str = new char[temp.cap];
	for (int i = 0; i < str1.siz; i++) {
		temp.str[i] = str1.str[i];
	}
	for (int i = str1.siz, j = 0; i < str2.siz + str1.siz; i++, j++) {
		temp[i] = str2.str[j];
	}
	temp.str[temp.siz] = '\0';

	return temp;
}

bool mstring::operator >(const mstring &other) {
	int s = min(siz, other.siz);
	for (int i = 0; i < s; i++) {
		if (str[i] > other.str[i])
			return 1;
		else if (str[i] < other.str[i])
			return 0;
	}
	if (siz > other.siz)
		return 1;
	return 0;
}

bool mstring::operator <(const mstring &other) {
	int s = min(siz, other.siz);
	for (int i = 0; i < s; i++) {
		if (str[i] < other.str[i])
			return 1;
		else if (str[i] > other.str[i])
			return 0;
	}
	if (siz < other.siz)
		return 1;
	return 0;
}

bool mstring::operator ==(const mstring & other) {
	if (siz != other.siz)
		return 0;
	for (int i = 0; i < siz; i++)
		if (str[i] != other.str[i])
			return 0;
	return 1;
}

bool mstring::operator >=(const mstring &other) {
	if (*this == other || *this > other)
		return 1;
	return 0;
}

bool mstring::operator <=(const mstring &other) {
	if (*this == other || *this < other)
		return 1;
	return 0;
}

char& mstring::operator [](int index) {
	return str[index];
}

//--------------------functions-------------------------------------------------------

int mstring::size() const {
	return siz;
}

int mstring::length() const {
	return siz;
}

void mstring::resize(int t) {
	char* temp = new char[t];
	for (int i = 0; i < t; i++) {
		if (i >= siz)
			temp[i] = ' ';
		else
			temp[i] = str[i];
	}
	delete[] str;
	siz = t;
	cap = power(t);
	str = new char[cap];
	str = temp;
	str[siz] = '\0';
}

void mstring::resize(int t, char c) {
	char* temp = new char[t];
	for (int i = 0; i < t; i++) {
		if (i >= siz)
			temp[i] = c;
		else
			temp[i] = str[i];
	}
	delete[] str;
	siz = t;
	cap = power(t);
	str = new char[cap];
	str = temp;
	str[siz] = '\0';
}

int mstring::capacity() const {
	return cap;
}

void mstring::clear() {
	delete[] str;
	siz = 0;
	cap = 2;
	str = new char[cap];
}

bool mstring::empty() {
	return !siz;
}

void mstring::shrink_to_fit() {
	char * temp = new char[siz];
	for (int i = 0; i <= siz; i++)
		temp[i] = str[i];
	delete[] str;
	cap = siz;
	str = new char[cap];
	for (int i = 0; i <= siz; i++)
		str[i] = temp[i];
	delete[] temp;
}

char& mstring::at(int index) throw (out_of_range) { //get the element in the index
	if (index > siz)
		throw out_of_range("invalid index");
	return str[index];
}

char mstring::back() { //get the last char

	if (!siz) {
		return '\0';
	} else
		return str[siz - 1];
}

char mstring::front() // get the first char
{
	if (!siz) {
		return '\0';
	}

	return str[0];
}

void mstring::push_back(char c) {
	if (siz + 1 < cap) {
		str[siz] = c;
		siz++;
		str[siz] = '\0';
	} else {
		char * temp = new char[siz + 1];
		cap = power(siz + 1);
		for (int i = 0; i < siz; i++) {
			temp[i] = str[i];
		}
		temp[siz] = c;
		siz++;
		delete[] str;
		str = new char[cap];
		for (int i = 0; i < siz; i++) {
			str[i] = temp[i];
		}
		str[siz] = '\0';
		delete[] temp;
	}
}

mstring& mstring::insert(int pos, const char *s) throw (out_of_range) {

	if (pos > siz)
		throw out_of_range("index Not valid !");
	char * p = new char[siz + strlen(s)];

	for (int i = 0; i < pos; i++)
		p[i] = str[i];

	for (int i = pos, j = 0; j < strlen(s); i++, j++)
		p[i] = s[j];

	for (int i = pos + strlen(s), j = pos; j < siz; j++, i++)
		p[i] = str[j];

	delete[] str;
	siz += strlen(s);
	cap = power(siz);
	str = new char[cap];
	for (int i = 0; i < siz; i++)
		str[i] = p[i];
	str[siz] = '\0';
	delete[] p;

	return *this;
}

mstring& mstring::insert(int pos, const mstring& str) throw (out_of_range) {
	if (pos > siz)
		throw out_of_range("invalid index");

	cap = power(siz + str.siz);
	siz = siz + str.siz;
	char* ctemp = new char[cap];
	for (int i = 0; i < pos; i++) {
		ctemp[i] = this->str[i];
	}
	for (int i = 0, l = pos; i < strlen(str.str); i++, l++) {
		ctemp[l] = str.str[i];
	}
	long long int temp = pos + str.siz;
	for (int i = pos; i < strlen(this->str); i++) {
		ctemp[temp++] = this->str[i];
	}
	delete[] this->str;
	this->str = new char[cap];
	for (int i = 0; i < strlen(ctemp); i++) {
		this->str[i] = ctemp[i];
	}
	this->str[siz] = '\0';
	delete[] ctemp;
	return *this;
}

mstring& mstring::insert(int pos, int n, char c) throw (out_of_range) {
	if (pos > siz)
		throw out_of_range("Not Valid!");
	siz = siz + n;
	if (siz >= cap)
		cap = power(siz);
	char* temp = new char[cap];
	for (int i = 0; i < pos; i++)
		temp[i] = str[i];
	for (int i = pos; i < pos + n; i++)
		temp[i] = c;
	for (int i = pos + n; i < siz; i++)
		temp[i] = str[i - n];
	delete[] str;
	str = new char[cap];
	for (int i = 0; i < siz; i++)
		str[i] = temp[i];
	str[siz] = '\0';
	delete[] temp;
	return *this;
}

mstring& mstring::append(const mstring& str) {
	long long int temp = siz + str.siz;
	int cnt = 0;
	if (temp < cap) {
		for (int i = siz; i < temp; i++)
			this->str[i] = str.str[cnt++];
		this->str[temp] = '\0';
		siz = temp;
		cap = power(siz);
		return *this;
	}
	cap = power(temp);
	char* ptemp = new char[temp];
	for (int i = 0; i < siz; i++) {
		ptemp[i] = this->str[i];
	}
	for (int i = siz; i < temp; i++) {
		ptemp[i] = str.str[cnt++];
	}
	delete[] this->str;
	this->str = new char[cap];
	for (int i = 0; i < temp; i++) {
		this->str[i] = ptemp[i];
	}
	this->str[temp] = '\0';
	siz = temp;
	delete[] ptemp;
	return *this;
}

mstring& mstring::append(const char* s) {
	long long int temp = siz + strlen(s);
	int cnt = 0;
	if (temp < cap) {
		for (int i = siz; i < temp; i++)
			this->str[i] = s[cnt++];
		this->str[temp] = '\0';
		siz = temp;
		cap = power(siz);
		return *this;
	}
	cap = power(temp);
	char* ptemp = new char[temp];
	for (int i = 0; i < siz; i++) {
		ptemp[i] = this->str[i];
	}
	for (int i = siz; i < temp; i++) {
		ptemp[i] = s[cnt++];
	}
	delete[] this->str;
	this->str = new char[cap];
	for (int i = 0; i < temp; i++) {
		this->str[i] = ptemp[i];
	}
	this->str[temp] = '\0';
	siz = temp;
	delete[] ptemp;
	return *this;
}

mstring& mstring::append(int n, char c) {
	for (int i = 0; i < n; i++)
		*(this) += c;
	return *this;
}

int mstring::find(const mstring& str, int pos) const {
	int temp;
	for (int i = pos - 1; i < this->siz; i++) {
		temp = i;
		for (int l = 0; l < str.siz; l++) {
			if (str.str[l] == this->str[temp]) {
				temp++;
			} else
				break;

			if (l == str.siz - 1)
				return i;
		}
	}
	return -1;
}

int mstring::find(char c, int pos) const {
	for (int i = 0; i < siz; i++)
		if (str[i] == c)
			return i;
	return -1;

}

int mstring::find(const char*s, int pos) const {
	int c = 0;
	for (int i = pos; i < siz; i++) {
		c = 0;
		int it = i;
		for (int j = 0; j < strlen(s); j++) {
			if (str[it] == s[j]) {
				it++;
				c++;
			}
		}
		if (c == strlen(s))
			return i;
	}
	return -1;
}

mstring& mstring::erase(int pos, int len) throw (out_of_range) {
	if (pos > siz || len + pos > siz)
		throw out_of_range("Not Valid!");
	char* temp = new char[cap];
	for (int i = 0; i < pos; i++)
		temp[i] = str[i];
	for (int i = pos + len, j = pos; i < siz; i++, j++)
		temp[j] = str[i];
	siz -= len;
	cap = power(siz);
	delete[] str;
	str = new char[cap];
	for (int i = 0; i < siz; i++)
		str[i] = temp[i];
	str[siz] = '\0';
	delete[] temp;
	return *this;
}

void mstring::swap(mstring& str) {
	char* fctemp = new char[this->cap];
	char* sctemp = new char[str.cap];

	for (int i = 0; i < this->siz; i++)
		fctemp[i] = this->str[i];
	for (int i = 0; i < str.siz; i++)
		sctemp[i] = str.str[i];

	long long int itemp;

	itemp = str.cap;
	str.cap = this->cap;
	this->cap = itemp;
	itemp = str.siz;
	str.siz = this->siz;
	this->siz = itemp;

	delete[] this->str;
	delete[] str.str;

	this->str = new char[this->cap];
	str.str = new char[str.cap];

	for (int i = 0; i < this->siz; i++)
		this->str[i] = sctemp[i];
	this->str[this->siz] = '\0';
	for (int i = 0; i < str.siz; i++)
		str.str[i] = fctemp[i];
	str.str[str.siz] = '\0';
}

void mstring::pop_back() {
	siz--;
	str[siz] = '\0';
}

int mstring::compare(const mstring & other) {
	if (*this > other)
		return 1;
	else if (*this == other)
		return 0;
	else
		return -1;
}

void mstring::toupper() {
	for (int i = 0; i < siz; i++) {
		if (str[i] >= 97 && str[i] <= 122)
			str[i] -= 32;
	}
}

void mstring::tolower() {
	for (int i = 0; i < siz; i++) {
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
	}
}

mstring mstring::substr(int pos, int len) const {
	mstring temp;
	temp.cap = temp.power(len);
	temp.str = new char[len];
	temp.siz = len;
	for (int i = pos, j = 0; i < pos + len; i++, j++)
		temp.str[j] = str[i];
	temp[temp.siz] = '\0';
	return temp;
}

mstring& mstring::replace(int pos, int len, const mstring& str) {
	cap = power(siz + str.siz);
	long long int temp;
	char* ctemp = new char[cap];
	for (int i = 0; i < pos; i++)
		ctemp[i] = this->str[i];
	for (int i = pos, l = 0; i < str.siz + pos; i++, l++)
		ctemp[i] = str.str[l];
	temp = str.siz + pos;
	for (int i = pos + len; i < this->siz; i++)
		ctemp[temp++] = this->str[i];
	delete[] this->str;
	this->str = new char[cap];
	for (int i = 0; i < temp; i++)
		this->str[i] = ctemp[i];
	this->str[temp] = '\0';
	return *this;
}

void mstring::reverse() {

	for (int i = 0, j = siz - 1; i < siz / 2; i++, j--) {
		char x = str[i];
		str[i] = str[j];
		str[j] = x;
	}
}

void mstring::reversewords() {

	mstring temp;
	mstring res;
	for (int i = siz - 1; i >= 0; i--) {

		if (str[i] != ' ') {
			temp += str[i];
		}
		if (str[i] == ' ' || i == 0) {
			temp.reverse();
			res += temp;
			res += ' ';
			temp.clear();
		}

	}

	*(this) = res;
}

int mstring::countwords() {

	if (empty()) {
		return 0;
	}
	int c = 1;
	int index = 0;
	for (int i = 0; i < siz; i++) {
		if (str[i] != ' ') {
			index = i;
			break;
		}
	}
	for (int i = 0; i < siz - 1; i++) {
		if (str[i] == ' ' && str[i + 1] != ' ' && i + 1 != index) {
			c++;
		}
	}

	return c;
}

void mstring::sortwords() {
	mstring s, temp;
	s = *this;
	int arrSize = s.countwords(), tempIndex = 0, index = 0;
	mstring * arrTemp = new mstring[arrSize];
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != ' ') {
			temp = s[i];
			tempIndex = i;
			break;
		}
	}
	for (int i = tempIndex + 1; i < s.size(); i++) {
		if (s[i] == ' ' && s[i - 1] != ' ') {
			arrTemp[index++] = temp;
			temp = "";
			continue;
		}
		if (s[i] == ' ' && s[i - 1] == ' ')
			continue;
		temp += s[i];
		if (i == s.size() - 1) {
			arrTemp[index] = temp;
			break;
		}
	}
	mstring value;
	int hole = -1;
	for (int i = 0; i < arrSize; i++) {
		value = arrTemp[i];
		hole = i;
		while (hole > 0 && arrTemp[hole - 1] > value) {
			arrTemp[hole].swap(arrTemp[hole - 1]);
			hole--;
		}
	}
	s = "";
	for (int i = 0; i < arrSize; i++) {
		s += arrTemp[i];
		if (i != arrSize - 1)
			s += " ";
	}
	delete[] arrTemp;
	*this = s;
}

void mstring::display() {
	int choice;
	cout << "1. left justify " << endl;
	cout << "2. middle justify" << endl;
	cout << "3. right justify" << endl;
	cin >> choice;
	if (choice == 1) {
		cout << *this;
	} else if (choice == 2) {
		for (int i = 0; i < 40 - siz; i++)
			cout << " ";
		cout << *this;
	} else if (choice == 3) {
		for (int i = 0; i < 80 - siz; i++)
			cout << " ";
		cout << *this;
	}
}
