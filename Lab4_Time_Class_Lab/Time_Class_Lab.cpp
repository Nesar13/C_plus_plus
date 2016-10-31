#include <iostream>

using namespace std;

class Time
{
private:
	int hour;
	int minutes;
	int seconds;

public:
	Time(); //default constructor
	Time(int, int, double); //construtor with 3 variables
	int get_hour();
	int get_minutes();
	double get_seconds();
	void setTime(int h, int m, double s);
	friend ostream& operator<< (ostream&, const Time&); //<< operator overload

};
class TimeSpan
{
private:
	int hour;
	int minutes;
	double seconds;

public:
	int get_hour();
	int get_minutes();
	double get_seconds();

	TimeSpan(); //defaut
	TimeSpan(double);
	friend ostream& operator<< (ostream&, const TimeSpan&);
};
Time::Time()
{
	hour = 0;
	minutes = 0;
	seconds = 0;
}

//Time::Time(int h, int m, double s)
//{
//	hour = 0;
//	minutes = 0;
//	seconds = 0;
//}
void Time::setTime(int h, int m, double s)
{
	hour = h;
	minutes = m;
	seconds = s;
}


int Time::get_hour()
{
	return hour;
}

int Time::get_minutes()
{
	return minutes;
}

double Time::get_seconds()
{
	return seconds;
}

ostream& operator<< (ostream& out, const Time& obj)
{
	cout << "[" << obj.hour << ":" << obj.minutes << ":" << obj.seconds << "]";
}





int main()
{
	Time dt2(13, 30, 0);
	cout << dt2 << endl;

	TimeSpan ts1(65.5);
	cout << ts1.get_minutes() << endl;
	cout << ts1.get_seconds() << endl;
}



/*Create two classes: Time and TimeSpan

 
Time should store a moment in time. It should have public
methods to retrieve the hour of the day (get_hour), 
minute of the day (get_minutes), seconds and decimal 
fractions of a second 
(get_seconds). It should have a constructor that 
accepts a time of day. For example:
 
Time dt2(13, 30);
 
You should overload the << operator so that you can 
cout a Time object. It should output in the following
format: [ h:m:s ] 
where each letter corresponds to a
stored piece of information. For example:
 
cout << dt2 << endl;
[ 13:30:0 ]
 
TimeSpan should store a time interval, and should have public methods to retrieve the number of hours and fractions of an hour (get_hours), minutes (get_minutes), seconds and decimal fractions of a second (get_seconds) stored in it. There should be a constructor that takes in a number of seconds. Overload << to allow outputting [ h:m:s ]. For example:
 
TimeSpan ts1(65.5);
cout << ts1 << endl;
cout << ts1.get_minutes() << endl;
cout << ts1.get_seconds() << endl;
[ 0:1:5.5 ]
1.09
65.5
 
Finally, overload the + operators so that you 
can add TimeSpans with other TimeSpans 
(the result of which is a TimeSpan) and 
TimeSpans with Times (the result of which is a Time).*/