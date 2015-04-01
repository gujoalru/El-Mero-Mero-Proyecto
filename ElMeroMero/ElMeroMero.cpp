// ElMeroMero.cpp : Defines the entry point for the console application.


#include <stdafx.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <fstream>
using namespace std;

struct supermercado
{
	int cant;
	double precio;
	char nombre_p[70];
}
super[10];
char name[75];
ofstream entrada;
ofstream entrada1;
ifstream entrada2("ProductosSuperFeo.txt");

float totalv = 0;
double totalar = 0;
double total = 0, isv = 0;
int canti = 1;
int resp = 0;
int c = 0;
void registrar()
{
	do
	{

		cout << "Ingrese cantidad que se vende: " << endl;
		cin >> super[canti].cant;
		entrada << "cantidad " << super[canti].cant << endl;
		entrada1 << super[canti].cant << " ";

		cout << "Ingrese el nombre del articulo: " << endl;
		cin >> super[canti].nombre_p;
		entrada << "Nombre producto: " << super[canti].nombre_p;
		entrada1 << super[canti].nombre_p << " ";
		cout << "Ingrese el valor de articulo: " << endl;
		cin >> super[canti].precio;
		entrada << "Precio: " << super[canti].precio << " " << endl;
		entrada1 << super[canti].precio << " ";
		canti=canti+1;
		c=c+1;
		cout << "\n\n " << endl;

	} while (c < resp);
}

void factura()
{
	system("cls");
	cout << "\t------------------Supermercado la mera mera---------------\t" << endl;
	cout << "\t-------------------Factura---------------------------------\t" << endl;
	cout << "Nombre: " << name << endl;


	cout << "Cant/Arti " << "\t " << "Nom/Art" << "  \t  " << "    Precio  " << endl;

	canti = 1;
	do

	{
		if (super[canti].cant == 0)
		{
			canti = 11;
			break;
		}

		cout << super[canti].cant << "        \t   " << super[canti].nombre_p << " \t   " << super[canti].precio << endl;
		totalv = totalv + (super[canti].precio * super[canti].cant);
		totalar = totalar + super[canti].cant;
		isv = isv + totalv*0.15;
		total = totalv + isv;
		

		canti++;
	} while (canti <= resp);
	entrada << "Total " << total << " " << endl;
	entrada1 << total << " ";
	entrada << "**************************" << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "Subtotal: " << totalv << endl;
	cout << "Impuesto: " << isv << endl;
	cout << "Total de articulos vendidos: " << totalar << endl;
	cout << "Total: " << total << endl;

	system("PAUSE");
}



int main()
{

	
	int op;
	cout << "Ingrese una opcion" << endl;
	cout << "1. Normal" << endl;
	cout << "2. Tavo" << endl;
	cin >> op;
	switch (op)
	{
	case 1:
		entrada.open("ProductosSuper.txt", ios::out | ios::app);
		entrada1.open("ProductosSuperFeo.txt", ios::out | ios::app);
		if ((entrada.fail()) && (entrada1.fail()))
		{
			cout << "ERROR AL ABRIR EL ARCHIVO" << "\n";
		}
		else
		{
			cout << "Supermercado de programacion cientificia I " << endl;
			cout << "Para finalizar ingrese 0" << endl;
			cout << "Ingrese nombre: " << endl;
			cin >> name;
			entrada << " Nombre factura:  " << name << " ";
			entrada1 << name << " ";
			cout << "Ingrese cuantos articulos desea comprar(que no exceda de 10 articulos): ";
			cin >> resp;
			if (resp>10)
			{
				system("cls");
				cout << "Error, cantidad excedida de articulos\nGracias por preferirnos";
				return 0;
			}
			else
			{
				registrar();
				factura();
				main();
			}
			
		}
		break;
	case 2:
		
			entrada2 >> name;
			entrada2 >> resp;
			entrada2 >> super[canti].nombre_p;
			entrada2 >> super[canti].precio;
			entrada2 >> total;
			
			for (int i = 0; i < resp; i++) 
			{
			cout << "Nombre: " << name << endl;
			cout << "Cantidad: " << resp << endl;
			cout << "Nombre del producto: " << super[canti].nombre_p << endl;
			cout << "precio: " << super[canti].precio << endl;
			cout << " " << endl;
			c = c + 1;
			} 
		cout << "total: " << total << endl;
		cout << " " << endl;
		system("cls");
		system("PAUSE");
		break;

	}
	return 0;
}

