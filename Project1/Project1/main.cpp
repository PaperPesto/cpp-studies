#include <iostream>
#include <memory>
#define log(x) std::cout << x << std::endl

// Importa perchè non ho ancora definito _MARIO_
#ifndef _MARIO_
#define _MARIO_
//importazioni
#endif

// Skippa perchè ho già definito _MARIO_
#ifndef _MARIO_
#define _MARIO_
//importazioni
#endif

// turorial https://www.youtube.com/watch?v=DTxHyVn0ODg

class Entity {
public:

	Entity() {
		
		std::cout << "Created entity!" << std::endl;
	}
	~Entity() {
		std::cout << "Destroyed entity!" << std::endl;
	}	
};

int main(int argc, char* argv[]) {

	log("hello world!");

	// Il tipo di un puntatore aiuta soltanto a capire che tipo di dato sta contenendo la variabile, non serve strettamente al puntatore
	void* ptr = 0;	// oppure posso mandarlo a null, #define NULL = 0

	char* buffer = new char[8];	// Inizializzo 8byte di memoria (nell'heap)
	memset(buffer, 0, 8);	// Mando a zero gli elementi nella memoria appena inizializzata

	char** dblptr = &buffer;
	// Se guardo in Debug -> Windows -> Memory1 e inserisco il valore del puntatore vedo che sta puntando al primo elemento dell'array (cioè al vettore)
	// Se allora guardo a cosa sta puntando (in little endian) quel puntatore arrivo direttamente agli elementi dell'array


	// 1
	Entity* e = new Entity();
	e->~Entity();

	// 2 - unique pointer
	// Non posso puntare lo stesso blocco di memoria da due unique_ptr diversi
	// definisco uno scope apposito
	{
		std::unique_ptr<Entity> entity(new Entity());	// Costruttore esplicito
		std::unique_ptr<Entity> entity2 = std::make_unique<Entity>();	// Chiamando make_unique
		// std::unique_ptr<Entity> e0 = entity2; // <- da errore
	}	// Appena esco da qui vengono distrutte entrambe le istanze


	// 3 - shared pointers
	// puntatori che memorizzano il numero di referenze che puntano allo stesso blocco di memoria (reference counting)
	// Quando il ref. count == 0 allora viene chiamato il decostruttore
	// Quando viene copiato un puntatore il ref.count incrementa di 1
	{
		std::shared_ptr<Entity> e0;
		{
			std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();	// count 1
			std::cout << "count " << sharedEntity.use_count() << std::endl;
			
			std::shared_ptr<Entity> sharedEntity2 = sharedEntity;	// questo funziona, count 2
			std::cout << "count " << sharedEntity.use_count() << std::endl;
			
			e0 = sharedEntity;	// count 3
			std::cout << "count " << sharedEntity.use_count() << std::endl;
		}	// Quando esco dallo scope distrugge sharedEntity e sharedEntity2, quindi couynt torna a 1

		std::cout << "count " << e0.use_count() << std::endl;	// count 1
	}

	// 4 - weak pointers
	// uguali agli shared pointers ma non incrementa il ref count
	{
		std::weak_ptr<Entity> e0;
		{
			std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();	// count 1
			std::cout << "count " << sharedEntity.use_count() << std::endl;

			e0 = sharedEntity;
			std::cout << "count " << sharedEntity.use_count() << std::endl;	// Non incrementa di 1
		}
	}
}