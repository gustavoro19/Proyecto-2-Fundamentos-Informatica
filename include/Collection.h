#ifndef COLLECTION_H
#define COLLECTION_H
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

class Collection
{
    public:
        Collection();
        int convertHour(int hour);
        bool availability(int hour);
        void setAppointPeriod(int hour, bool hourChange);
        bool getAppointPeriod(int hour);
        void reservAppoint(int hour); //emily R
        string stateAppoint(); // vero
        int cantAvailability(); // vero R
        void deleteAppoint(int hour); // ser o no ser xd
        virtual ~Collection();

    protected:

    private:
        bool appointPeriod[12];
};

#endif // COLLECTION_H
