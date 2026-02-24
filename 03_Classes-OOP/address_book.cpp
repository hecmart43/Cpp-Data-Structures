#include <iostream>//Cin and cout
#include <string>//Strings
#include <ctime>//Use computeres current date
using namespace std;//No std::cout just cout
struct Node 
{
    //Below Block: The nodes for the list
    string lname, fname, street, city, state, zip;
    int bMonth = 0, bDay = 0, aMonth = 0, aDay = 0;
    Node* next = nullptr;
};
Node* head = nullptr;//starts with first node
//Below Block: Pulls current date from the local computer
void getToday(int& m, int& d) 
{
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    m = now->tm_mon + 1; d = now->tm_mday;
}
//Below Block: creates the new node and allocates memeory for the node
void addRecord()
{
    //Below Block: All the info the user will input for the new entry
    Node* p = new Node;
    cout << "Last name: ";   getline(cin, p->lname);
    cout << "First name: ";  getline(cin, p->fname);
    cout << "Street: ";      getline(cin, p->street);
    cout << "City: ";        getline(cin, p->city);
    cout << "State: ";       getline(cin, p->state);
    cout << "ZIP: ";         getline(cin, p->zip);
    cout << "Birthday (month day): "; cin >> p->bMonth >> p->bDay;
    cout << "Anniversary (month day, 0 0 = none): "; cin >> p->aMonth >> p->aDay;
    cin.ignore();
    //Below Block: Alphabetizes each new entry
    if (!head || p->lname < head->lname) { p->next = head; head = p; return; }
    Node* cur = head;
    while (cur->next && cur->next->lname < p->lname) cur = cur->next;
    p->next = cur->next; cur->next = p;
}
//Below Block: Asks which entry the user wants to delete
void deleteRecord() 
{
    string l, f; cout << "Enter last name: "; getline(cin, l);
    cout << "Enter first name: "; getline(cin, f);
    //Below Block: Wll walk user through the list and if the user wants to delete it will free memory and prompt "Deleted"
    Node *cur = head, *prev = nullptr;
    while (cur) {
        if (cur->lname == l && cur->fname == f) 
        {
            if (!prev) head = cur->next; else prev->next = cur->next;
            delete cur; cout << "Deleted.\n"; return;
        }
        prev = cur; cur = cur->next;
    }
    cout << "Not found.\n";
}
//Below Block: Ask user which entry to edit
void changeRecord() 
{
    string l, f; cout << "Enter last name: "; getline(cin, l);
    cout << "Enter first name: "; getline(cin, f);
    //Below Block: Loops through list till entry is found/prompts for new info/updates and prompts "updated"/if not found prompts "not found"
    for (Node* cur = head; cur; cur = cur->next) if (cur->lname == l && cur->fname == f) 
    {
        cout << "New street: "; getline(cin, cur->street);
        cout << "New city: "; getline(cin, cur->city);
        cout << "New state: "; getline(cin, cur->state);
        cout << "New ZIP: "; getline(cin, cur->zip);
        cout << "New birthday (m d): "; cin >> cur->bMonth >> cur->bDay;
        cout << "New anniversary (m d): "; cin >> cur->aMonth >> cur->aDay;
        cin.ignore(); cout << "Updated.\n"; return;
    }
    cout << "Not found.\n";
}
//Below Block: Prints each enbtry in the address book
void displayBook() 
{
    for (Node* cur = head; cur; cur = cur->next) 
    {
        cout << cur->lname << ", " << cur->fname << "\n"
             << cur->street << "\n"
             << cur->city << ", " << cur->state << " " << cur->zip << "\n"
             << "Birthday: " << cur->bMonth << "/" << cur->bDay << "\n"
             << "Anniversary: " << cur->aMonth << "/" << cur->aDay << "\n\n";
    }
    if (!head) cout << "(Address book is empty)\n";
}
//Below Block: Gets the current date off the computer/looks through entries for any birthdays for today/if none prints no birthdays today
void birthdayCards() 
{
    int m, d; getToday(m, d);
    bool any = false;
    //Below Block: Goes through each entry/ if someone matches then a message will print/if none it will prompt no birhtdays today
    for (Node* cur = head; cur; cur = cur->next)
        if (cur->bMonth == m && cur->bDay == d) 
        {
            cout << "Dear " << cur->fname
                 << ",\nHope your birthday is really wonderful and this coming year is the best yet!\n"
                 << "Love, Joanne\n\n";
            any = true;
        }
    if (!any) cout << "No birthdays today.\n";
}
//Below Block: Same as the birthdays but anniversaries
void anniversaryCards() 
{
    int m, d; getToday(m, d);
    bool any = false;
    //Below Block: Same as the birthdays but anniversaries
    for (Node* cur = head; cur; cur = cur->next)
        if (cur->aMonth == m && cur->aDay == d) 
        {
            cout << "Dear " << cur->fname
                 << ",\nWishing you a very happy anniversary and many more years of joy together!\n"
                 << "Warmly, Joanne\n\n";
            any = true;
        }
    if (!any) cout << "No anniversaries today.\n";
}
//Below Block: Program starts/shows the the menu with the seven options
int main() 
{
    int choice;
    do 
    {
        cout << "\n1) Add\n2) Delete\n3) Change\n4) Display\n5) Birthday Cards\n6) Anniversary Cards\n7) Exit\nChoice: ";
        //Below Block: Reads user input/ will print an error if not an option
        if (!(cin >> choice)) { cin.clear(); cin.ignore(10000, '\n'); continue; }
        cin.ignore();
        //Below Block: Depending on the users choice it will bring up the correct function
        if (choice==1) addRecord();
        else if (choice==2) deleteRecord();
        else if (choice==3) changeRecord();
        else if (choice==4) displayBook();
        else if (choice==5) birthdayCards();
        else if (choice==6) anniversaryCards();
    } 
    //Below Block: The program will keep looping until 7 is choses as the users input and will end the program
    while (choice!=7);
    return 0;
}