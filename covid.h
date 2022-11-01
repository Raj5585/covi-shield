#include <iostream>
#include <fstream>
#include <limits>
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include <string>
#include <time.h>
#include<vector>
using namespace std;
void login_ask();
void menu();
void show();
void show2();

class covid
{
    int age;
    char name[30];
    char profession[20];
    char address[20];
    char mobile_number[15];
    char gender; 

public:
    void add_new();
    void delte_record();
    void search_data();
    void modify_data();
    void setdata();
    void search_by_address();
    void search_by_age();
    void search_by_profession();
    void search_by_phone();
    void search_by_gender();
    void show_list();
    int total_case();
   // int total_death();
  //  int total_recovered();
    void loc_search();
    void local_show_list();
    bool search(int r)
    {
        if (age == r)
        {
            return true;
        }
        else
            return false;
    }


};