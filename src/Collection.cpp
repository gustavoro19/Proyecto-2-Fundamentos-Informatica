#include "Collection.h"

Collection::Collection()
{
    for(int i = 0; i < 12; i++){
        appointPeriod[i] = 0;
    }
}

int Collection::convertHour(int hour)
{
    int index = 0;

    for(int i = 7; i < 19; i++){
        if(i != hour){
            index++;
        }else{
            break;
        }
    }
    return index;
}

bool Collection::availability(int hour)
{
    if(appointPeriod[convertHour(hour)] == 0){
        return true;
    }else {
        return false;
    }
}

void Collection::setAppointPeriod(int hour,bool hourChange)
{
        appointPeriod[convertHour(hour)] = hourChange;
}

bool Collection::getAppointPeriod(int hour)
{
    return appointPeriod[convertHour(hour)];
}

void Collection::reservAppoint(int hour)
{
    if(availability(hour)){
        appointPeriod[convertHour(hour)] = 1;
    }else{
        cout << "LA HORA DE CITA QUE DESEA YA ESTA OCUPADA" << endl;
        system("pause");
    }
}

string Collection::stateAppoint()
{
    stringstream s;
    s << "\t\t\t\t\tESTADO DE LAS CITAS: " << endl << endl;
    for(int i = 7; i < 19; i++){
        s << "| " << i  << ":00" << " |";
    }
    s << endl << "|------||------||------||-------||-------||-------||-------||-------||-------||-------||-------||-------|"  << endl;
    for(int i = 0; i < 12;i++){
        if(i < 3){
            s << "|  " << appointPeriod[i] << "   |";
        }else{
            s << "|   " << appointPeriod[i] << "   |";
        }
    }
    s << endl;
    return s.str();
}

int Collection::cantAvailability()
{
    int cont = 0;
    for(int i = 0; i < 12;i++){
        if(appointPeriod[i] == 0){
            cont++;
        }
    }
    return cont;
}

void Collection::deleteAppoint(int hour)
{
    if(availability(hour)){
        cout << "NO EXISTE CITA A ESTA HORA" << endl;
    }else{
        appointPeriod[convertHour(hour)] = 0;
    }
}

Collection::~Collection(){}
