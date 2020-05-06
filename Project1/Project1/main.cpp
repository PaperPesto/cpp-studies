#include <iostream>
#define log(x) std::cout << x << std::endl

// turorial https://www.youtube.com/watch?v=DTxHyVn0ODg

int main(int argc, char* argv[]) {

	log("hello world!");

	// Il tipo di un puntatore aiuta soltanto a capire che tipo di dato sta contenendo la variabile, non serve strettamente al puntatore
	void* ptr = 0;	// oppure posso mandarlo a null, #define NULL = 0

	char* buffer = new char[8];	// Inizializzo 8byte di memoria (nello stack o nell'heap?)
	memset(buffer, 0, 8);	// Mando a zero gli elementi nella memoria appena inizializzata

	char** dblptr = &buffer;
	// Se guardo in Debug -> Windows -> Memory1 e inserisco il valore del puntatore vedo che sta puntando al primo elemento dell'array (cioè al vettore)
	// Se allora guardo a cosa sta puntando (in little endian) quel puntatore arrivo direttamente agli elementi dell'array
}