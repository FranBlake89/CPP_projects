//Francisco Castillo
//fcastillo-rojas1
#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_
#include <ostream>
#include <iostream>
namespace sdds
{
	const int MAX_NO_OF_ITEMS = 10;
	class MenuItem
	{
		char* m_content{};
		public:
		MenuItem();
		MenuItem(const char* content);
		MenuItem(const MenuItem& menuitem) = delete;
		std::ostream& display(std::ostream& os) const;
		MenuItem& operator=(const MenuItem& menuitem) = delete;
		~MenuItem();
		friend class Menu;
	};
	class Menu
	{
		char* m_title{};
		MenuItem* m_item[MAX_NO_OF_ITEMS]{};
		int m_indentation{};
		int m_num{};
		public:
		Menu();
		Menu(const char* title, int inde = 0);
		Menu(const Menu& menu);
		Menu& operator=(const Menu& menu);
		Menu& operator=(const char* title);
		Menu& operator<<(const char* title);
		explicit operator bool() const ;
		operator int() const;
		void setEmpty() ;
		bool isEmpty() const;
		void display() const;
		void clear();
		void add(const char* title);
		int run() const ;
		int select(std::istream&) const;
		~Menu();
	};
}
#endif // !SDDS_MENU_H_
