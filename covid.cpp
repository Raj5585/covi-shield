#include"covid.h"
void getstring(char* a)
{
    char b;
    b = ' ';
    int i = 0;
    while (b != '\n')
    {
        b = getchar();
        a[i] = b;
        i++;
    }
    a[i - 1] = '\0';
}
void login_ask()
{
    char username[30], password[20];
    int choice;
    cout << "\n\n\t\t\t\t*********************************************";
    cout << "\n\t\t\t\tWELCOME TO THE COVID MANAGEMENT SYSTEM\n";
    cout << "\t\t\t\t*********************************************\n";

    cout << "\n\n\n\t\t\t1: ENTER AS ADIM\n\n\n\t\t\t2: ENTER AS LOCAL\n\n\n\t\t\tYour choice:";
    cin >> choice;
    if (choice == 2)
    {
        covid obj;
        char c;
        do {
            system("cls");
            int total = obj.total_case();
            //total death 
            string deathcount;
            std::vector <string> totaldeath;

            ifstream inf("death.txt");
                while (getline(inf, deathcount))
                {
                    totaldeath.push_back(deathcount);                 
                }

                //total Recovered 
                string recovered;
                std::vector <string> totalrecovered;

                ifstream inf2("recovered.txt");
                while (getline(inf2, recovered))
                {
                    totalrecovered.push_back(recovered);
                }  

                int active_cases = (total - totalrecovered.size() - totaldeath.size());

            cout << "\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 COVID MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n"
                << endl;
            cout << "\n\t\t\t*****************************************" << endl;
            cout << "\t\t\t\t LOCAL SECTION ";
            cout << "\n\t\t\t*****************************************\n\n";
              fflush(stdin);
            cout << "\n\t TOTAL CASES: \t\t\t\t\tTOTAL RECOVERED : " <<endl<<"\t\t"<< total <<"\t\t\t\t\t\t" << totalrecovered.size()<< endl;
            cout << "\n\t ACTIVE CASES:\t\t\t\t\t TOTAL DEATH: " << endl << "\t\t" << active_cases << "\t\t\t\t\t\t" << totaldeath.size() << endl;

          //  cout << "\t\t\t\t\tTOTAL RECOVERED:" << endl << "\t\t\t\t\t\t" << totalrecovered.size() << endl;
          //  cout << "\n\t\t\t\t\t TOTAL DEATH: " << endl <<"\t\t\t\t\t\t"<<totaldeath.size() << endl;
//
            obj.loc_search();
            cout << endl<<"Do you want to search again?[y or n]" << endl;
            cin >> c;
        } while (c == 'y' || c == 'Y');
        //_getch();
        cout << endl << endl<< "\t\t\t\t\tTHANK YOU!!" << endl;
    }
    if (choice == 1)
    {
        cout << "\n\n\t\t\t\t*********************************************";
        cout << "\n\t\t\t\t\tLOGIN\n";
        cout << "\t\t\t\t*********************************************\n";

        int i = 0, cap = 0, capt = 0;
        string name, password;
        char ch;
        const char ENTER = 13;
        const char  BACK = 8;
        cout << "\n\n\t\t\t\t\tUSER NAME:  ";
        cin.ignore();
        getline(cin, name);
        std::cout << "\n\n\t\t\t\t\tPASSWORD: ";
        while ((ch = _getch()) != ENTER)
        {
            if (ch != BACK) {
                password.push_back(ch);
            }
            if (ch == BACK && password.length() != 0) {
                password.pop_back();
            }

        }
     //   srand(time(0));
      //  cap = rand();
      //  cout << "\n\t\t\t\t\t CAPTCHA:->  " << cap << endl;
      //  cout << " Please enter the valid CAPTCHA :-   ";
       // cin >> capt;
        bool check = true;
        if ((name.compare("admin") == 0) && (password.compare("admin1") == 0)) { //&& capt == cap) {
            while (check)
            {
                covid obj;
                int choice;
                cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 COVID MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
                    << endl;
                cout << "\t\t\n\n\n Powered By:- COVID HELP AND RESCUE  " << endl;
                menu();
                cout << "\n\t\n\tChoose according to your need : ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    system("cls");
                    obj.add_new();
                    break;
                case 2:
                    system("cls");
                    obj.delte_record();
                    break;
                case 3:
                    system("cls");
                    obj.search_data();
                    break;
                case 4:
                    system("cls");
                    obj.modify_data();
                    break;
                case 5:
                    system("cls");
                    cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\tTHANK YOU!!";
                    check = false;
                    break;

                default:
                    system("cls");
                    cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\tTHANK YOU!!";
                    check = false;
                    break;
                }
              
            };
    
            
        }
            else
            {
                system("cls");
                cout << "\n\t\t\t\t\tSORRY WRONG PASSWORD!!!";
                cout << "\n\t\t\t\t\t\n\n\n";  
                _getch();
            }
    }
}

void menu()
{
    system("cls");
    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 COVID MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
        << endl;
    cout << "\t\t\t\t\t\t Powered By:-  COVI-SHIELD" << endl
        << endl;
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t\tMENU";
    cout << "\n\t\t\t*****************************************\n";
    cout << "\n\t\t1: Add NEW Record\t\t\t 2: DELETE RECORD" << endl;
    cout << "\n\t\t3: SEARCH   \t\t\t\t 4: MODIFY" << endl;
    cout << "\n\t\t5: EXIT" << endl;
}
void covid::add_new()
{
    covid obj;
    ofstream in;
    in.open("covid_record1.txt", ios::out | ios::binary | ios::app);
    obj.setdata();
    in.write((char*)&obj, sizeof(obj));
    if (!in.good())
    {
        cout << "\nerror writing data\n";
    }
    cout << "YOUR DATA HAS BEEN SUCCESSFULLY INSERTED " << endl;
    _getch;
    in.close();
}

void covid::delte_record()
{
    bool check;
    covid obj;

    ifstream in;
    in.open("covid_record1.txt");

    ofstream ion;
    ion.open("covid_record2.txt");


    char name1[20];

    in.seekg(0, in.beg);
    int flag = 0;

     int  total_recovered = 0;
    int  total_death = 0;

    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 COVID MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
        << endl;
    cout << "\t\t\t\t\t\t Powered By:- COVI-SHIELD " << endl
        << endl;
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t DELETE DATA ";
    cout << "\n\t\t\t*****************************************\n\n";
    fflush(stdin);
    cin.ignore();
    char inp;
    cout << "Reason to delete data.[R for recovered and D for death]" << endl;
      cin>>inp;

    if (inp == 'r' || inp == 'R') {
        total_recovered++;
        ofstream recov("recovered.txt", ios::app);
        recov << total_recovered<<endl;
        check = true;
    }
    else if (inp == 'd' || inp == 'D') {
        total_death++;
        ofstream death("death.txt", ios::app);
        death << total_death<<endl;
        check = true;
    }
    else {
        cout << "INVALID OPTION!";
        check = false;
    }
    while (check) {
        cout << "Enter the name of patient  in the list " << endl;
        cin.ignore();
        getstring(name1);
        show();
        in.read((char*)&obj, sizeof(obj));
        while (!in.eof())
        {
            if (strcmp(obj.name, name1) == 0)
            {
                obj.show_list();
                cout << endl<<"This record has been deleted" << endl;
                flag = 1;              
                _getch();
            }
            else
            {
                ion.write((char*)&obj, sizeof(obj));

            }           

            in.read((char*)&obj, sizeof(obj));
        }
        if (flag == 0)
        {
            cout <<endl<< "Name  was  not found " << endl;
            _getch();
        }

        in.close();
        ion.close();
        remove("covid_record1.txt");
        rename("covid_record2.txt", "covid_record1.txt");
        break;
    }
   
}

void covid::modify_data()
{
    covid obj;

    fstream in;
    in.open("covid_record1.txt", ios::in | ios::out | ios::binary);
    char name1[20];

    in.seekg(0, in.beg);
    int flag = 0;

    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 COVID MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
        << endl;
    cout << "\t\t\t\t\t\t Powered By:- COVI-SHIELD " << endl
        << endl;
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t ADDRESS SEARCHING ";
    cout << "\n\t\t\t*****************************************\n\n";
    fflush(stdin);
    cin.ignore();
    cout << "Enter the name of patient  in the list " << endl;
    getstring(name1);


    in.read((char*)&obj, sizeof(obj));
    while (!in.eof())
    {
        if (strcmp(obj.name, name1) == 0)
        {
            cout << "\n\t\t Enter name of patient :-  ";
            getstring(obj.name);
            fflush(stdin);
            cout << "\n\t\t Enter your permanent address :-  ";
            getstring(obj.address);
          //  fflush(stdin);
            cout << "\n\t\t Enter age of patient:- ";
            cin >> obj.age;
            cin.ignore();
            cout << "\n\t\t Enter profession of patient :-  ";
            getstring(obj.profession);
            fflush(stdin);
            cout << "\n\t\t Enter gender (M|F)of patient :-  ";
            cin >> obj.gender;
            fflush(stdin);

            cout << "\n\t\t Enter your Mobile number :- ";
            cin >> obj.mobile_number;
            _getch;

            in.seekp(int(in.tellp()) - sizeof(*this));
            in.write((char*)&obj, sizeof(obj));
            in.seekp(0);
            cout << "YOUR RECORD HAS BEEN MOSIFIED" << endl;
        }



        in.read((char*)&obj, sizeof(obj));
    }
    if (flag == 0)
    {
        cout << "Name  was  not found " << endl;
    }

    in.close();
}
void covid::setdata()
{
    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 COVID MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
        << endl;
    cout << "\t\t Powered By:- COVI-SHIELD " << endl
        << endl;
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t RECORDING INFORMATION ";
    cout << "\n\t\t\t*****************************************\n\n";

    cin.ignore();
    cout << "\n\t\t Enter name of patient :-  ";

    getstring(name);
    cout << "\n\t\t Enter your permanent address :-  ";
    getstring(address);

    cout << "\n\t\t Enter age of patient:- ";
    cin >> age;
    cin.ignore();

    cout << "\n\t\t Enter profession of patient :-  ";
    getstring(profession);

    cout << "\n\t\t Enter gender (M|F)of patient :-  ";
    gender = getchar();
    cin.ignore();

    cout << "\n\t\t Enter your Mobile number :- ";
    cin >> mobile_number;
    fflush(stdin);
    cin.ignore();
}
void covid::search_data()
{

    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 COVID MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
        << endl;
    cout << "\t\t\t\t\t\t Powered By:-  COVI-SHIELD " << endl
        << endl;
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\tSEARCHING STATISTICS";
    cout << "\n\t\t\t*****************************************\n\n";
    cout << "From which option you want to perform searching " << endl;
    cout << "\n\t\t 1. By address \t\t\t 2. By Age " << endl;
    cout << "\n\t\t 3. By profession \t\t 4. By gender " << endl;
    cout << "\n\t\t 5. By phone number" << endl;
    cout << "\n\n\t\tEnter your choice ...............";
    int ch;
    cin >> ch;
    switch (ch)
    {
    case 1:
        system("cls");
        search_by_address();
        _getch();
        break;
    case 2:
        system("cls");
        search_by_age();
        _getch();
        break;
    case 3:
        system("cls");
        search_by_profession();
        _getch();
        break;
    case 4:
        system("cls");
        search_by_gender();
        _getch();
        break;
    case 5:
        system("cls");
        search_by_phone();
        _getch();
        break;
    default:
        system("cls");
        cout << "ENTER VALID OPTION" << endl;
        menu();
    }
}
void covid::search_by_address()
{
    fstream in;
    in.open("covid_record1.txt", ios::in | ios::out | ios::binary);
    covid obj;
    in.seekg(0, in.beg);

    //std::cout << sizeof(in) << "\n";
    int flag = 0;
    int a = 0;
    char address_num[20];
    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 COVID MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
        << endl;
    cout << "\t\t\t\t\t\t Powered By:-COVI-SHIELD " << endl
        << endl;
    cout << "\n\t\t\t*****************************************"<<endl;
    cout << "\t\t\t\t ADDRESS SEARCHING ";
    cout << "\n\t\t\t*****************************************\n\n";
    fflush(stdin);
    cin.ignore();
    cout << "Enter your Address " << endl;
    getstring(address_num);
    show();
    in.read((char*)&obj, sizeof(obj));
   
    while (!in.eof())
    {
        if (strcmp(obj.address, address_num) == 0)
        {
            obj.show_list();
            flag = 1;
            a = a + 1;  

        }
        //in.seekg(0, in.cur);

        in.read((char*)&obj, sizeof(obj));
    }
    cout << "\n\n\n\t\t No of Cases :- " << a << endl;
    if (flag == 0)
    {
        cout << "Address was  not found " << endl;
    }
    in.close();
}

void covid::search_by_age()
{
    int a = 0;
    fstream in;
    in.open("covid_record1.txt", ios::in | ios::binary);
    covid obj;
    in.seekg(0, in.beg);

    int flag = 0;
    int  p = 0;
    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 COVID MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
        << endl;
    cout << "\t\t\t\t\t\t Powered By:- COVI-SHIELD " << endl
        << endl;
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t AGE SEARCHING ";
    cout << "\n\t\t\t*****************************************\n\n";
    cout << "enter Age by which you want to search " << endl;
    cin >> a;
    show();
    do
    {
        if (obj.search(a))
        {
            obj.show_list();
            flag = 1;
            p++;
        }

    } while (in.read((char*)&obj, sizeof(obj)));

    if (flag == 0)
    {
        cout << "Age you entered is not found" << endl;
    }
    cout << "\n\n\n\nNo of patient by this age: " << p;
    in.close();
}
void covid::search_by_phone()
{
 
    fstream in;
    in.open("covid_record1.txt", ios::in | ios::out | ios::binary);
    covid obj;
    in.seekg(0, in.beg);
    int flag = 0;
    char mobile[10];
    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 COVID MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
        << endl;
    cout << "\t\t\t\t\t\t Powered By:- COVI-SHIELD " << endl
        << endl;
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t PROFESSION SEARCHING ";
    cout << "\n\t\t\t*****************************************\n\n";
    fflush(stdin);
    cin.ignore();
    cout << "Enter your Mobile Number" << endl;

    getstring(mobile);
    show();
    in.read((char*)&obj, sizeof(obj));
    while (!in.eof())
    {
        if (strcmp(obj.mobile_number, mobile) == 0)
        {
            obj.show_list();
            flag = 1;
        }
        in.read((char*)&obj, sizeof(obj));
    }
    if (flag == 0)
    {
        cout << "Mobile number was  not found " << endl;
    }
    in.close();

}
void covid::search_by_profession()
{
    fstream in;
    in.open("covid_record1.txt", ios::in | ios::out | ios::binary);
    int a = 0;
    covid obj;
    in.seekg(0, in.beg);


    int flag = 0;
    char profession[20];
    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 COVID MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
        << endl;
    cout << "\t\t\t\t\t\t Powered By:- COVI-SHIELD " << endl
        << endl;
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t PROFESSION SEARCHING ";
    cout << "\n\t\t\t*****************************************\n\n";
    fflush(stdin);
    cin.ignore();
    cout << "Enter your profession" << endl;

    getstring(profession);
    show();
    in.read((char*)&obj, sizeof(obj));
    while (!in.eof())
    {
        if (strcmp(obj.profession, profession) == 0)
        {
            obj.show_list();
            flag = 1;
            a = a + 1;
        }
        //in.seekg(0, in.cur);

        in.read((char*)&obj, sizeof(obj));
    }
    cout << "\n\n\n\t\t No of Cases of this profession is:- " << a << endl;
    if (flag == 0)
    {
        cout << "Address was  not found " << endl;
    }
    in.close();
}
void covid::search_by_gender()
{

    fstream in("covid_record1.txt");
    // in.open("covid_record1.txt", ios::in | ios::binary);
    //covid obj;
    in.seekg(0, in.beg);

    int flag = 0;
    char g;
    int p = 0;
    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 COVID MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
        << endl;
    cout << "\t\t\t\t\t\t Powered By:- COVI-SHIELD " << endl
        << endl;
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t GENDER SEARCHING ";
    cout << "\n\t\t\t*****************************************\n\n";
    cout << "Enter gender by which you want to search " << endl;
    cin >> g;
    show();
    in.read((char*)this, sizeof(covid));
    while (!in.eof())
    {
        if (toupper(g) == toupper(gender))
        {
            show_list();
            flag = 1;
            p++;
        }
        in.read((char*)this, sizeof(covid));
    }
    if (flag == 0)
    {
        cout << "The gender you entered does not exist " << endl;
    }
    cout << "\n\n\n No of cases suffering from this gender is:- " << p << endl;
    in.close();
} 


void covid::show_list()
{
    cout << "\n";
    cout << setw(20) << setiosflags(ios::left) << name;
    cout << setw(20) << address;
    cout << setw(10) << age;
    cout << setw(18) << profession;
    cout << setw(13) << gender;
    cout << setw(15) << mobile_number;
}
void show()
{
    cout << setw(20) << setiosflags(ios::left) << "Name ";
    cout << setw(20) << "Address";
    cout << setw(10) << "Age";
    cout << setw(18) << "Profession";
    cout << setw(13) << "gender";
    cout << setw(15) << "Mobile No.";
}


int covid::total_case()
{
    fstream in("covid_record1.txt");
    in.seekg(0, in.beg);
    int p = 0;
    in.read((char*)this, sizeof(covid));
    while (!in.eof())
    {
        p++;
        in.read((char*)this, sizeof(covid));
    }
    in.close();
    return p;
}




void covid :: loc_search() {
    fstream in;
    in.open("covid_record1.txt", ios::in | ios::out | ios::binary);
    covid obj;
    in.seekg(0, in.beg);

    int flag = 0;
    int a = 0;
    char address_num[20];
    cin.ignore();
    cout <<endl<< "\t\t\tENTER ADDRESS YOU WANT TO VIEW DATA:";
    getstring(address_num);
    show2();
    in.read((char*)&obj, sizeof(obj));

    while (!in.eof())
    {
        if (strcmp(obj.address, address_num) == 0)
        {
            obj.local_show_list();
            flag = 1;
            a = a + 1;

        }

        in.read((char*)&obj, sizeof(obj));
    }
    cout << "\n\n\n\t\t No of Cases :- " << a << endl;
    if (flag == 0)
    {
        cout << "Address was  not found " << endl;
    }
    in.close();
}

void covid::local_show_list()
{
    cout <<endl;
    cout << setw(10) << age;
    cout << setw(18) << profession;
    cout << setw(13) << gender;
}
void show2()
{
    cout << setw(10) << "Age";
    cout << setw(18) << "Profession";
    cout << setw(13) << "gender";
}