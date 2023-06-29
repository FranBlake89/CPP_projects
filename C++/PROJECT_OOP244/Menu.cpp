//Francisco Castillo
//fcastillo-rojas1
#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <iomanip>
#include <cstring>
using namespace std;
using namespace sdds;
namespace sdds
{
	MenuItem::MenuItem()
	{
		m_content = nullptr;
	}
	MenuItem::MenuItem(const char* content)
	{
		if (content != nullptr)
		{
			m_content = new char[strlen(content) + 1];
			strcpy(m_content, content);
		}
		else
		{
			content = nullptr;
		}
	}
	std::ostream& MenuItem::display(std::ostream& os) const
	{
		os << m_content;
		return os;
	}
	MenuItem::~MenuItem()
	{
		delete[] m_content;
		m_content = nullptr;
	}

		Menu::Menu()
	{
		m_title = nullptr;
		m_item[0] = nullptr;
		m_indentation = -1;
		m_num = 0;
	}
	void Menu::clear() 
	{
		Menu::setEmpty();
		//MenuItem::MenuItem();
	}
	Menu::Menu(const char* title, int inde)
	{
		if (title != nullptr && title[0] != '\0')
		{
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
			m_indentation = inde;
			m_num = 0;
		}
		else
		{
			*this = Menu();
		}
	}
	Menu::Menu(const Menu& menu)
	{
		*this = menu;
	}
	Menu& Menu::operator=(const Menu& menu)
	{
		if (!menu.isEmpty())
		{
			setEmpty();
			m_title = new char[strlen(menu.m_title) + 1];
			strcpy(m_title, menu.m_title);
			m_indentation = menu.m_indentation;
			for (int i = 0; i < menu.m_num; i++)
			{
				add(menu.m_item[i]->m_content);
			}
		}
		else
		{

				setEmpty();
		}
		return *this;
	}
	Menu& Menu::operator=(const char* title)
	{
		if (title != nullptr)
		{
			if (strlen(title) != 0)
			{
				delete[] m_title;
				m_title = nullptr;
				m_title = new char[strlen(title) + 1];
				strcpy(m_title, title);
				m_indentation = 0;
				for (int i = 0; i < m_num; i++)
				{
					delete[] m_item[i];
					m_item[i] = nullptr;
				}
			}
		}
		else
		{
			setEmpty();
		}
		return *this;
	}
	void Menu::add(const char* title)
	{
		if (!isEmpty() && title != nullptr && m_num < MAX_NO_OF_ITEMS)
		{
			m_item[m_num] = new MenuItem(title);
			m_num++;
		}
		else
		{
			setEmpty();
		}
	}

	Menu & Menu::operator<<(const char* title)
	{
		add(title);
		return *this;
	}
	void Menu::display() const
	{
		if (isEmpty())
		{
			cout << "Invalid Menu!" << endl;
		}
		else if (m_title != 0)
		{
			cout << string(m_indentation * 4, ' ') << m_title << endl;
			if (!isEmpty() && m_num != 0)
			{
				for (int i = 0; i < m_num; i++)
				{
					cout << string(m_indentation * 4, ' ') << i + 1 << "- " << m_item[i]->m_content << endl;
				}
				cout << string(m_indentation * 4, ' ') << "> ";
			}
			if (m_item[0] == nullptr)
			{
				cout << "No Items to display!" << endl;
			}
		}
	}
	Menu::operator bool() const
	{
		return (!isEmpty());
	}
	Menu::operator int() const
	{
		return run();
	}

		void Menu::setEmpty()
	{
		delete[] m_title;
		m_title = nullptr;
		m_indentation = -1;
		for (int i = 0; i < m_num; i++)
		{
			delete m_item[i];
			m_item[i] = nullptr;
		}
		m_num = 0;
	}
	bool Menu::isEmpty() const
	{
		return m_title == nullptr;
	}
	int Menu::run() const
	{
		display();
		return select(cin);
	}
	int Menu::select(std::istream& is) const
	{
		int temp;
		int flag;
		if (m_item[0] != nullptr)
		{
			do
			{
				flag = -1;
				if (!(is >> temp))
				{
					cin.clear();
					cin.ignore(1024, '\n');
					cout << "Invalid Integer, try again: ";
					flag = 0;
				}
				else if (temp > m_num || temp < 1)
				{
					cout << "Invalid selection, try again: ";
					flag = 0;

				}
				else
				{
					cin.ignore(1024, '\n');
				}
			} while (flag == 0);
		}
		else
		{
			temp = 0;
		}
		return temp;
	}
	Menu::~Menu()
	{
		delete[] m_title;
		m_title = nullptr;
		for (int i = 0; i < m_num; i++)
		{
			delete m_item[i];
			m_item[i] = nullptr;
		}
	}
}
