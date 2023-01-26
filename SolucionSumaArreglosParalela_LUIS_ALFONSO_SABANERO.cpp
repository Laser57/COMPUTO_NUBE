// SolucionSumaArreglosParalela_LUIS_ALFONSO_SABANERO.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// LUIS ALFONSO SABANERO ESQUIVEL A01273286
// SUMA DE ARREGLO EN EJECUCION PARALELA
// COMPUTO EN LA NUBE

#include <iostream>

#ifdef _OPENMP
#include <omp.h>
#endif

using namespace std;

#define N 10
#define chunk 5
#define mostrar 10
void imprimearreglo(float* d);
int main()
{	
	int semilla;
	cout << "Define la semilla para la suma de arreglos: ";
	cin >> semilla;
	cout << "Sumando arreglos en paralelo: " << endl;
	float a[N], b[N], c[N]; 
	int i;
	for ( i = 0; i < N; i++) {
		a[i] = 1 * semilla *15;
		b[i] = i * semilla;

	}
	int pedazos= chunk;
	#pragma omp parallel for \
	shared(a,b,c,pedazos) private(i)\
	schedule(static, pedazos)

	for ( i = 0; i < N; i++) {
		c[i] = a[i] + b[i];
	}
		cout << "imprimendo los primeros: "<< mostrar <<" valores del arreglo a" << endl;
		imprimearreglo(a);
		cout << "imprimendo los primeros: " << mostrar << " valores del arreglo b" << endl;
		imprimearreglo(b);
		cout << "imprimendo los primeros: " << mostrar << " valores del arreglo c" << endl;
		imprimearreglo(c);
	
}
	void imprimearreglo(float* d)
	{
		for (int x=0; x < mostrar; x++) {
			cout << d[x] << "-";
			cout << endl;
		}
	}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
