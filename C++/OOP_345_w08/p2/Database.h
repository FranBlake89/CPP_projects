
/*
> Name: Francisco Castillo
> Course: OOP
> Section: NDD
> Seneca ID: 148904212
> Seneca email: fcastillo-rojas1@myseneca.ca
> Date of completion: 2023-mm-dd

* I confirm that I am the only author of this file
 and the content was created entirely by me.
*/


#ifndef SDDS_DATABASE_H
#define SDDS_DATABASE_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <memory>

namespace sdds {
    const size_t maxSize{20};

    enum class Err_Status
    {
        Err_Success,
        Err_NotFound,
        Err_OutOfMemory,
    };

    template <typename T>
    class Database 
    {
    private:
        static std::shared_ptr<Database<T>> m_database;
        size_t m_entries;
        std::string m_keys[20] {};
        T m_values[maxSize] {};
        std::string m_file;

        Database(const std::string& filename) {
            m_file = filename;
            m_entries = 0;
            std::cout << "[" << this << "]" << " Database(const std::string&)" << std::endl;
            std::ifstream file(filename);
            std::string key {};
            T value {};
            while ((file >> key >> value) && m_entries < maxSize) {
                std::replace(key.begin(), key.end(), '_', ' ');
                encryptDecrypt(value);
                SetValue(key, value);
            }
            file.close();
        };

        // helper function
        void encryptDecrypt(T& value) {};
    public:
        static std::shared_ptr<Database> getInstance(const std::string& filename) {
            return (m_database) ? m_database : m_database = std::shared_ptr<Database<T>>(new Database<T>(filename));
        };
        Err_Status GetValue(const std::string& key, T& value) {
            Err_Status status { Err_Status::Err_NotFound };
            int flag = 0;
            for (size_t i = 0; i < m_entries && flag == 0; i++) {
                if (m_keys[i] == key) {
                    value = m_values[i];
                    status = Err_Status::Err_Success;
                    flag = 1;
                }
            }
            return status;
        };
        Err_Status SetValue(const std::string& key, const T& value) {
            Err_Status status { Err_Status::Err_OutOfMemory };
            if (m_entries < maxSize) {
                m_keys[m_entries] = key;
                m_values[m_entries] = value;
                m_entries++;
                status = Err_Status::Err_Success;
            }
            return status;
        };
        ~Database() {
            std::cout << "[" << this << "]" << " ~Database()" << std::endl;
            std::ofstream databaseBackup(m_file + ".bkp.txt");
            for (size_t i = { 0 }; i < m_entries; i++) {
                encryptDecrypt(m_values[i]);
                databaseBackup << std::left << std::setw(25) << m_keys[i] << " -> " << m_values[i] << std::endl;
            }
        };
    };

    template<>
    void Database<std::string>::encryptDecrypt(std::string& value) {
        const char temp[]{ "secret encryption key" };
        for (char& c : value) {
            for (const char& k : temp) {
                c = c ^ k;
            }
        }
    }

    template<>
    void Database<long long>::encryptDecrypt(long long& value) {
        const char temp[]{ "super secret encryption key" };
        char* byte = reinterpret_cast<char*>(&value);
        size_t no_bytes = sizeof(value);
        for (size_t i = 0; i < no_bytes; i++) {
            for (const char& k : temp) {
                byte[i] = byte[i] ^ k;
            }
        }
    }

    template<typename T>
    std::shared_ptr<Database<T>> Database<T>::m_database = nullptr;
}

#endif // SDDS_DATABASE_H
