#include <conio.h>
#include <iostream>
#include <string>

using namespace std;

class atm{
    private :

        long int account_no;
        string name;
        int PIN;
        double balance;
        string mobile_no;

    public :

        void setData(long int account_no_a, string name_a, int PIN_a, double balance_a, string mobile_no_a)
        {
            account_no = account_no_a;
            name = name_a;
            PIN = PIN_a;
            balance = balance_a;
            mobile_no = mobile_no_a;
        }

        long int get_account_no()
        {
            return account_no;
        }

        string get_name()
        {
            return name;
        }

        int get_PIN()
        {
            return PIN;
        }

        double get_balance()
        {
            return balance;
        }

        string get_mobile_no()
        {
            return mobile_no;
        }


        void withdraw(int amount)
        {
            if(amount >0 && amount < balance)
            {
                cout << endl << "Please Collect your cash. ";
                balance = balance - amount ;
                cout << endl << "Your remaining balance is : " << balance;
                _getch();
            }
            else{
                cout << endl << "Invalid Input or Insufficient Balance";
                _getch();
            }
        }

        void change_mobile_no(string old_mobile_no, string new_mobile_no)
        {
            if(mobile_no == old_mobile_no)
            {
                mobile_no = new_mobile_no;
                cout << endl << "Successfully Updated your New Mobile No. ";
                _getch();
            }
            else{
                cout << endl << "Invalid Input !!";
            }
        }

};

int main ()
{
    int choice = 0,enterPIN;
    long int enterAccountNo;

    system("cls");

    atm user;

    user.setData(12345678, "John", 1234, 50000, "9876543210");

    do {
        system("cls");
        
        cout << endl << "-------Welcome to the ATM-------" << endl;
        cout << endl << "Enter your Account No - ";
        cin >> enterAccountNo;

        cout << endl << "Enter the PIN - ";
        cin >> enterPIN;

        if((enterAccountNo == user.get_account_no())&& (enterPIN == user.get_PIN()) )
        {
          do{ 
             int amount = 0;

            string old_mobile_no, new_mobile_no;

            system("cls");

            cout << endl << "-------Welcome to the ATM-------" << endl;
            cout << endl << "Select Options - ";
            cout << endl << "1. Check Balance ";
            cout << endl << "2. Cash Withdraw ";
            cout << endl << "3. Show user details ";
            cout << endl << "4. Update Mobile No. ";
            cout << endl << "5. Exit " << endl; 
            cin >>  choice;

            switch(choice)
            {
                case 1 :
                    cout << endl << "Your Balance is : " << user.get_balance();

                    _getch();
                    break;

                case 2 : 
                    cout << endl << "Enter the amount : ";
                    cin >> amount ;

                    user.withdraw(amount);
                    break;

                case 3 : 
                    cout << endl << "**User Details are -" << endl;
                    cout << endl << "Account Number : " << user.get_account_no();
                    cout << endl << "PIN : " << user.get_PIN();
                    cout << endl << "Name : " << user.get_name();
                    cout << endl << "Balance: " << user.get_balance(); 
                    cout << endl << "Mobile No: " << user.get_mobile_no();
                    _getch();
                    break;
                
                case 4 :
                    cout << endl << "Enter your Old Mobile No: ";
                    cin >> old_mobile_no;

                    cout << endl << "Enter your New Mobile No :";
                    cin >> new_mobile_no;

                    user.change_mobile_no(old_mobile_no, new_mobile_no);
                    break;

                case 5 : 
                    exit(0);

                default :
                    cout << endl << "Invalid Choice !!";
                    _getch();
            }
          }while(1);
        }
        else {
            cout << "Invalid Account Number or PIN !!";
            _getch();
        }
        
    } 
    while(1);
}