#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal *horde[10];

	// Animal myAnimal;
	// Animal *testAnimal;
	// testAnimal->makeSound();
	// delete testAnimal;

	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			horde[i] = new Dog();
		else
			horde[i] = new Cat();
	}
	std::cout << horde[0]->getType() << std::endl;
	std::cout << horde[5]->getType() << std::endl;

	Brain *brain;
	brain = &horde[0]->getBrain();
	brain->setIdea("im really dumb", 0);
	brain->setIdea("me too", 1);
	brain->setIdea("mooooooooo", 2);
	std::cout << horde[0]->getBrain().getIdea(0) << std::endl;
	std::cout << horde[0]->getBrain().getIdea(1) << std::endl;
	std::cout << horde[0]->getBrain().getIdea(2) << std::endl;


	for (int i = 0; i < 10; i++)
		delete horde[i];

	std::cout << "deep copy checks\n" << std::endl;

	Dog *dogA = new Dog;
	Dog *dogB = new Dog(*dogA);

	delete dogA;
	delete dogB;


	Cat *catA = new Cat;
	Cat *catB = new Cat(*catA);

	delete catA;
	delete catB;


	return (0);
}
