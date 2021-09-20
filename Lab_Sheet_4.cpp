#include <bits/stdc++.h>
using namespace std;

enum Languages{
    ENGLISH, FRENCH, GERMAN
};

struct Show{
    int id, duration;
    Languages language;
    Show(){}
    Show(int sid, int sduartion, Languages slanguage){
        id = sid;
        duration = sduartion;
        language = language;
    }
};

class Customer{
    public:
    string username, phonenumber;
    int watchHours;
    Show watchedShows[1000];
    int index;
    Customer(){}
    Customer(string uname, string phone){
        username = uname;
        phonenumber = phone;
        watchHours = 32;
        index = 0;
    }
    virtual void watch(Show show){
        if(watchHours-show.duration >= 0 && show.language == ENGLISH){
            watchHours = watchHours - show.duration;
            watchedShows[index++] = show;
            cout << username << " watched show id : " << show.id << endl;
        }
        else if(show.language != ENGLISH){
            cout << username << " only english language is allowed for this subscription" << endl;
        }
        else{
            cout << "exceeds watch limit" << endl;
        }
    }
    virtual void displayCustomer(){
        cout << "username: " << username << endl << "phone: " << phonenumber << endl; 
    }

    virtual void displayShowIds(){
        for(int i=0;i<index;i++)
            cout << watchedShows[i].id <<",  ";
        cout << endl;
    }
};

class PremiumCustomer: public Customer{
    public:
    Languages preferredLanguage;
    PremiumCustomer(): Customer(){}
    PremiumCustomer(string uname, string phone, Languages lang):Customer(uname, phone){
        preferredLanguage = lang;
        watchHours = -1;
    }
    void watch(Show show){
        watchedShows[index++] = show;
        cout << username << " username watched show with id : " << show.id<<endl;
    }
    void displayCustomer(){
        string lang;
        switch(preferredLanguage){
            case FRENCH:
                lang = "FRENCH";
                break;
            case GERMAN:
                lang = "GERMAN";
                break;
            default:
                lang = "ENGLISH";
        }
        cout << "username: "<<username<<" "<<"\nphone numeber : "<<phonenumber<<endl;
        cout << "preferred Language: "<<preferredLanguage<<endl;
    }
};

template<class T, int max>
class Account{
    public:
        T customers[max];
        int maxCustomers;
        int index;

        Account(){
            maxCustomers = max;
            index = 0;
        }

        void addCustomer(T cust){
            if(index < max)
                customers[index++] = cust;
            else
                cout << "customer limit exceeded"<<endl;
        }
        void displayCustomers(){
            for(int i=0;i<index;i++){
                customers[i].displayCustomer();
            }
        }
};


int main(){
    Account<Customer, 5> acc1;
    acc1.addCustomer(Customer("User1", "985555"));
    acc1.addCustomer(Customer("User2", "986666"));

    acc1.displayCustomers();
    Account<PremiumCustomer, 10> acc2;
    acc2.addCustomer(PremiumCustomer("PUser1", "987777", GERMAN));
    acc2.addCustomer(PremiumCustomer("PUser2", "988888", FRENCH));
    acc2.displayCustomers();
    Show shows[] = {Show(1, 7, ENGLISH), Show(2, 7, FRENCH), Show(3, 10, GERMAN), Show(4, 17, ENGLISH)};
    acc1.customers[0].watch(shows[3]);
    acc1.customers[0].watch(shows[2]);
    for(int i=0; i<3; i++){
    acc2.customers[0].watch(shows[3]);
    }
    cout<<"Watched shows for "<<acc1.customers[0].username<<":\n";
    acc1.customers[0].displayShowIds();
    cout<<"Watched shows for "<<acc2.customers[0].username<<":\n";
    acc2.customers[0].displayShowIds();
}