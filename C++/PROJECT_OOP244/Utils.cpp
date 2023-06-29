/*
Francisco Castillo
fcastillo-rojas1@myseneca.ca
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
#include "Utils.h"

namespace sdds {
    bool Utils::resp(istream& istr) {
        char res;
        char newline;
        do {
            res = istr.get();
            newline = istr.get();
            if (newline != '\n') {
                istr.ignore(1000, '\n');
                res = 'x';
            }
        } while (res != 'y' && res != 'Y' && res != 'n' && res != 'N'
            && cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ");
        return res == 'y' || res == 'Y';

    }
    void Utils::read(int& val, int min, int max, const char* ErrorMess, istream& is) { //*
        bool ok;
        char newline;
        const char* orgMes = ErrorMess;
        const char invalidInt[] = "Invalid Integer, try again: ";
        do {
            is >> val;
            newline = is.get();
            if (is.fail() || newline != '\n') {
                ok = false;
                is.clear();
                is.ignore(1000, '\n');
                ErrorMess = invalidInt;
            }
            else {
                ok = val <= max && val >= min;
                ErrorMess = orgMes;
            }
        } while (!ok && cout << ErrorMess);
    }
    void Utils::read(
        long long& val,
        long long min,
        long long max, const char* ErrorMess, istream& is) {
        bool ok;
        char newline;
        do {
            is >> val;
            newline = is.get();
            if (is.fail() || newline != '\n') {
                ok = false;
                is.clear();
                is.ignore(1000, '\n');
            }
            else {
                ok = val <= max && val >= min;
            }
        } while (!ok && cout << ErrorMess);
    }
    void Utils::read(char* str, int len, const char* errorMessage, istream& is) {//***
        bool ok=false;
        do {
            ok = true;
            is.getline(str, std::streamsize(len) + 1, '\n');
            if (is.fail()) {
                is.clear();
                is.ignore(1000, '\n');
                ok = false;
            }
        } while (!ok && cout << errorMessage);
    }
    void Utils::read(char* str, int minlen, int maxlen, const char* errorMessage, istream& is) { //**
        unsigned int lenSTR;
        lenSTR = 0;
        lenSTR = std::strlen(str);
        do {
            read(str, maxlen, errorMessage);
            lenSTR = strlen(str);
        } while ( lenSTR < unsigned (minlen) && cout << errorMessage);
    }
    void Utils::toUpper(char* str) {
        
        while (*str) {
            *str = toupper(*str);
            str++;
           
        }
    }
    string Utils::upperString(const char* str) {
        unsigned int i;
        char temp;
        string newStr;
        unsigned int len;
        len = strlen(str);

        for (i = 0; i < len; i++) {
            temp = toupper(str[i]);
            newStr.append(1, temp);
        }

        return newStr;
    }
    void Utils::lowerstrcpy(char* string, const char* source)
    {
        unsigned int i;
        char temp;
        std::string str;
        unsigned int len;
        len = strlen(source);

        for (i = 0; i < len; i++) {
            temp = tolower(source[i]);
            str.append(1, temp);
        }

        strcpy(string, str.c_str());
    }
    char* Utils::read(istream& is) {
        char* data = new char[ReadBufferSize];
        char* str = data;
        int noOfBuffers = 1;
        bool done;
        do {
            done = true;
            is.getline(str, ReadBufferSize, '\n');
            if (is.fail()) {
                noOfBuffers++;
                char* temp = new char[(ReadBufferSize - 1) * noOfBuffers + 1];
                strcpy(temp, data);
                delete[] data;
                data = temp;
                str = data + (ReadBufferSize - 1) * (noOfBuffers - 1);
                is.clear();
                done = false;
            }
        } while (!done);

        return data;
    }
    int Utils::strlen(const char* str) {
        int len = 0;
        while (str[len]) {
            len++;
        }
        return len;
    }

    void Utils::strcpy(char* des, const char* src, int len) {
        int i;
        
        for (i = 0; src[i] && (len < 0 || i < len); i++) {
            des[i] = src[i];
        }
        des[i] = 0; // turning the char array des in to a cString by null terminating it.

    }
}