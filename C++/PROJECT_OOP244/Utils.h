/*
Francisco Castillo
fcastillo-rojas1@myseneca.ca
*/
#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__
#include <iostream>
namespace sdds {
    const unsigned int ReadBufferSize = 40;
    struct Utils {
        static bool resp(std::istream& is = std::cin);
        static void read(int& val, int min, int max, const char* errorMessage = "", std::istream& is = std::cin);
        static void read(long long& val, long long min, long long max, const char* errorMessage = "", std::istream& is = std::cin);
        static void read(char* str, int len, const char* errorMessage = "", std::istream& is = std::cin);
        static void read(char* str, int minlen, int maxlen, const char* errorMessage = "", std::istream& is = std::cin);
        static char* read(std::istream& is = std::cin);
        static void toUpper(char* str);
        static std::string upperString(const char* str);
        static void lowerstrcpy(char* string, const char* source);
        static int strlen(const char* str);
        static void strcpy(char* des, const char* src, int len = -1);
    };
}
#endif
