#include <iostream>//Cout and cin
using namespace std;//cout and cin without std::
class SchoolCalendar//keeps the date and whatever may happen on that date together when it prints
{
private:
    int month, week, day;//stores "curret" date in the m/w/d format
    bool warnerOn;//admin option for the warning to turn on or off
    bool warnedAlready = false;//prints only once date is reached for warning 
    const int warnM = 1, warnW = 1, warnD = 3;//date that will trigger the “last day to drop” message
    //Below Block: prints the warning message once date is reached
    void maybeWarn()
    {
        //Below Block: Once warning displayed once it wont show again
        if (warnerOn && !warnedAlready && month == warnM && week == warnW && day == warnD)
        {
            cout << "TODAY IS THE LAST DAY TO DROP THE COURSE\n";
            warnedAlready = true;//Wont repeat on the same date or later
        }
    }
public:
    //Below Block: default constructor 1/1/1, warner OFF
    SchoolCalendar() : month(1), week(1), day(1), warnerOn(false), warnedAlready(false) {}
    //Below Block: parameterized constructor sets the date range and format
    SchoolCalendar(int m, int w, int d) : warnerOn(false), warnedAlready(false)
    {
        month = (m < 1) ? 1 : (m > 12 ? 12 : m);
        week  = (w < 1) ? 1 : (w > 4  ? 4  : w);
        day   = (d < 1) ? 1 : (d > 7  ? 7  : d);
    }
    void setWarner(bool on) { warnerOn = on; }//turn warner ON or OFF

    //Below Block: move forward by one day 
    void incrementDay() 
    {
        //Below Block: cant go beyond 12/4/7
        if (month == 12 && week == 4 && day == 7) 
        {
            return;
        }
        //Below Block: Ensures each portion of the date rolls over to the next week and month when day seven is incremented forward
        if (day < 7) 
        {
            day++;
        } else {
            day = 1;
            if (week < 4) 
            {
                week++;
            } else 
            {
                week = 1;
                if (month < 12) 
                {
                    month++;
                }
            }
        }
        //Below Block: After advancing day forward asks if want warning for new date
        maybeWarn();
    }
    //Below Block: prints the new date
    void displayDate() const 
    {
        cout << month << "/" << week << "/" << day << "\n";
    }
};
int main() 
{
    SchoolCalendar cal;//Starts at 1/1/1, warner OFF
    //Below Block: shows the starting date
    cout << "Initialize calendar (default 1/1/1). Current date:\n";
    cal.displayDate();
    //Below Block: Ask the user to input whether or not they want the warning
    cout << "Turn warner on? (y/n): ";
    char c; if (!(cin >> c)) return 0;
    cal.setWarner(c == 'y' || c == 'Y');
    cout << ((c=='y'||c=='Y') ? "Warner ON\n" : "Warner OFF\n");
    //Below Block: Asks user if they want to advance by a day/yes it advances one day/no exits the loop
    char more = 'y';
    while (true) 
    {
        cout << "Increment another day? (y/n): ";
        if (!(cin >> more)) break;
        if (more == 'y' || more == 'Y') 
        {
            cal.incrementDay();
            cout << "Current date: ";
            cal.displayDate();
        } else 
        {
            break;
        }
    }
    //Below Block: states exiting when no slected
    cout << "Exiting.\n";
    return 0;
}