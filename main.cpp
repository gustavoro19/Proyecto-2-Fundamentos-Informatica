// Estudiantes: Ricardo Morataya Sandoval, Gustavo Rojas,Sergio Piedra,Emily Rojas,Veronica Delgado
// Objetivo del programa: Crear un sistema de reserva de citas medicas
// Fecha de entrega: 23/04/2018
// Curso: Fundamentos de Informática, Universidad Nacional, Campus Nicoya. Prof. EVB.

#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "Collection.h"
#define ARRIBA 72
#define ABAJO 80
#define ENTER 13

using namespace std;
void enter();
void menu_principal(Collection &a);
int menu(const char *titulo,const char *opciones[],int n);
void instrucciones();
void gotoxy(int x,int y);
void reservAppoint(Collection &a);
void availability(Collection &a);
void stateAppoint(Collection &a);
void cantReserv(Collection &a);
void cantAvailability(Collection &a);
void deleteAppoint(Collection &a);


int main()
{
    Collection Appo;
    system("COLOR F0");
    system("mode con: cols=106 lines=15");
    menu_principal(Appo);
    system("cls");
    gotoxy(25,7);
    cout << "EL PROGRAMA SE CERRARA DESPUES DE APRETAR UNA TECLA...";
    system("pause>nul");
    return 0;
}

void menu_principal(Collection &Appo)
{

    int opcion;
    bool repite = true;

    const char *titulo = "CITAS MEDICAS";
    const char *opciones[] = {"RESERVAR CITA","VERIFICAR DISPONIBILIDAD DE CITA","ESTADO DE CITAS","CANTIDAD DE CITAS RESERVADAS", "CANTIDAD DE CITAS DISPONIBLES", "CANCELAR CITA", "SALIR"};

    int n = 7;

    do{
        opcion = menu(titulo,opciones,n);
        switch(opcion)
        {
            case 1:
                system("cls");
                reservAppoint(Appo);
                enter();
                break;
            case 2:
                system("cls");
                availability(Appo);
                enter();
                break;
            case 3:
                system("cls");
                stateAppoint(Appo);
                enter();
                break;
            case 4:
                system("cls");
                cantReserv(Appo);
                enter();
                break;
            case 5:
                system("cls");
                cantAvailability(Appo);
                enter();
                break;
            case 6:
                system("cls");
                deleteAppoint(Appo);
                enter();
                break;
            case 7:
                repite = false;
                break;

        }
    }while(repite);
}

int menu(const char *titulo,const char *opciones[],int n)
{
    int opcionSeleccionada = 1;
    int tecla; // se guardara la tecla precionada por el ususario
    bool repite = true;

    do{
        system("cls");
        instrucciones();
        gotoxy(5, 3 + opcionSeleccionada); cout << "==>";

        //Imprime el titulo
        gotoxy(15,2); cout << titulo;

        //Imprime las opciones

          for(int i = 0; i < n; i++){
            gotoxy(10, 4 + i);
            cout << i+1 << ") " << opciones[i] << endl;
            }

            do{
                tecla = getch();
            }while(tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);

            switch(tecla){

                case ARRIBA:

                    opcionSeleccionada--;

                    if(opcionSeleccionada < 1){
                        opcionSeleccionada = n;
                    }

                    break;
                case ABAJO:

                    opcionSeleccionada++;

                    if(opcionSeleccionada > n)
                    {
                        opcionSeleccionada = 1;
                    }

                    break;
                case ENTER:

                    repite = false;

                    break;
            }

        }while(repite);

    return opcionSeleccionada;
}

void enter()
{
    int tecla;
    cout << "Presione 'Enter' para continuar...";
    do{
        tecla = getch();
    }while(tecla != ENTER);
}

void reservAppoint(Collection &Appo)
{
    int hour;
    gotoxy(15,2);
    cout << "SISTEMA PARA RESERVAR UNA CITA DE 7 A 18(HORA MILITAR)" << endl << endl;
    cout << "\tINGRESE LA HORA QUE DESEA RESERVAR: ";
    cin >> hour;
    if(Appo.availability(hour)){
        Appo.setAppointPeriod(hour,hour);
        cout << "\n\tSE HA RESERVADO CORRECTAMENTE A LAS " << hour << ":00" << endl;
    }else{
        cout << "\n\tLA HORA DESEADA SE ENCUENTRA OCUPADA" << endl;
    }
    cout <<"\t";
}

void availability(Collection &Appo)
{
    int hour;
    gotoxy(15,2);
    cout << "SISTEMA DE DISPONIBILIDAD DE CITA" << endl << endl;
    cout << "\tHORA QUE DESEA VERIFICAR: ";
    cin >> hour;
    if(Appo.availability(hour)){
        cout << "\n\t LA HORA: " << hour << ":00 ESTA DISPONIBLE" << endl << endl;
    }else{
        cout << "\n\tLA HORA: " << hour << ":00 NO ESTA DISPONIBLE" << endl << endl;
    }
    cout << "\t";
}

void stateAppoint(Collection &Appo)
{
    cout << Appo.stateAppoint() << endl;
}

void cantReserv(Collection &Appo)
{
    gotoxy(15,2);
    cout << "SISTEMA CONTADOR DE  CANTIDAD DE CITAS RESERVADAS" << endl << endl;
    cout << "\tLA CANTIDAD DE CITAS RESERVADAS SON: " << 12 - Appo.cantAvailability() << endl << endl;
    cout << "\t";
}

void cantAvailability(Collection &Appo)
{
    gotoxy(15,2);
    cout << "SISTEMA CONTADOR DE  CANTIDAD DE CITAS DISPONIBLES" << endl << endl;
    cout << "\tLA CANTIDAD DE CITAS DISPONIBLES SON: " << Appo.cantAvailability() << endl << endl;
    cout << "\t";
}

void deleteAppoint(Collection &Appo)
{
    int hour;
    gotoxy(15,2);
    cout << "SISTEMA DE CANCELACION DE CITA" << endl << endl;
    cout << "\tHORA QUE DESEA CANCELAR: ";
    cin >> hour;
    if(Appo.availability(hour) == 0 ){
        Appo.deleteAppoint(hour);
        cout << "\n\t LA HORA: " << hour << ":00 ESTA CANCELADA" << endl << endl;
    }else{
        cout << "\n\tLA HORA: " << hour << ":00 NO ESTABA RESERVADA" << endl << endl;
    }
    cout << "\t";
}


void instrucciones()
{
    gotoxy(50,2);
    cout << "\tINSTRUCCIONES" << endl;
    gotoxy(50,4);
    cout << "| 1.USE LAS TECLA ARRIBA PARA SUBIR EN EL MENU.";
    gotoxy(50,5);
    cout << "| 2.USE LAS TECLA ABAJO PARA BAJAR EN EL MENU.";
    gotoxy(50,6);
    cout << "| 3.USE LAS TECLA ENTER PARA SELECCIOAR.";
    gotoxy(50,7);
    cout << "|";
    gotoxy(50,8);
    cout << "| CREADORES:";
    gotoxy(50,9);
    cout << "| 1.RICARDO MORATAYA";
    gotoxy(50,10);
    cout << "| 2.GUSTAVO ROJAS";
    gotoxy(50,11);
    cout << "| 3.SERGIO PIEDRA";
    gotoxy(50,12);
    cout << "| 4.EMILY ROJAS";
    gotoxy(50,13);
    cout << "| 5.VERONICA DELGADO";
}


void gotoxy(int x,int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos);
}
