#include <iostream>
#include <string>
using namespace std;
class Date
{
protected:
    int year;
    int month;
    int day;
public:
    Date() {}
    Date(int ye, int mo, int da) : year(ye), month(mo),day(da){}
    void addDay(int da) { day = da; }
    void addMonth(int mo) { month = mo; }
    void addYear(int yer) { year = yer; }
    void print() {
        cout << year <<" - "<< month << " - " << day << endl;
    }
};
class Event
{
protected:
    string title;
    Date date;
public:
    Event() {}
    Event(string titl, const Date&d) : title(titl),date (d){}
    virtual void print() {
        cout << title << " ";
        date.print();
    }
};
class RecurringEvent : public Event
{
public:
    RecurringEvent(string date, const Date&d) : Event( date, d){}
    virtual Event** occurrences(int) = 0;
};
class DailyEvent : public RecurringEvent {
public:
    DailyEvent(string title, const Date& d) : RecurringEvent(title, d) {}
    Event** occurrences(int) override {
        Event** notify = new Event * [3];
        for (int i = 0; i < 3; i++)
            notify[i] = new Event(title, date);
        return notify;
    }
};
class WeeklyEvent : public RecurringEvent {
public:
    WeeklyEvent(string title, const Date& d) :  RecurringEvent(title, d){}
    Event** occurrences(int) override {
        Event** notify = new Event * [3];
        for (int i = 0; i < 3; i++)
            notify[i] = new Event(title, date);
        return notify;
    }
};
class MonthlyEvent : public RecurringEvent {
public:
    MonthlyEvent(string title, const Date& d) :  RecurringEvent(title, d){}
    Event** occurrences(int) override {
        Event** notify = new Event * [3];
        for (int i = 0; i < 3; i++)
            notify[i] = new Event(title, date);
        return notify;
    }
};
int main() {
    RecurringEvent** rec = new RecurringEvent * [3];
    rec[0] = new DailyEvent("client meeting", Date(2022, 06, 8));
    rec[1] = new WeeklyEvent("lecture", Date(2022, 06, 8));
    rec[2] = new MonthlyEvent("project monitoring", Date(2022, 06, 8));
    for (int i = 0; i < 3; i++) {
        Event** occurr = rec[i]->occurrences(3);
        for (int j = 0; j < 3; j++) {
            occurr[j]->print();
            cout << endl;
        }
    }
    return 0;
}