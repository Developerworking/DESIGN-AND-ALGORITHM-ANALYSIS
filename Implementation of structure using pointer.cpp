#include <iostream>
#include <string> // for std::string
#include <memory> // for std::make_unique and std::unique_ptr

// Define a structure representing a person
struct Person {
    std::string name; // Name of the person
    int age;           // Age of the person
    float height;      // Height of the person (in meters)
};

// Function to create a new person with given details
Person* createPerson(const std::string& name, int age, float height) {
    // Allocate memory for a new Person and return a pointer to it
    Person* person = new Person;
    person->name = name;
    person->age = age;
    person->height = height;
    return person;
}

// Function to print the details of a person
void printPerson(const Person* person) {
    if (person != nullptr) { // Ensure pointer is valid
        std::cout << "Name: " << person->name << ", ";
        std::cout << "Age: " << person->age << ", ";
        std::cout << "Height: " << person->height << " meters" << std::endl;
    } else {
        std::cout << "Invalid person pointer!" << std::endl;
    }
}

// Function to delete a person (clean up memory)
void deletePerson(Person* person) {
    delete person; // Free the dynamically allocated memory
}

int main() {
    // Create a new Person using a pointer
    Person* person1 = createPerson("John Doe", 30, 1.75f);

    // Print the person's details
    printPerson(person1);

    // Modify the person's details
    person1->age += 1; // Increase age by 1
    person1->height += 0.05f; // Increase height by 0.05 meters

    // Print the updated person's details
    printPerson(person1);

    // Free the allocated memory
    deletePerson(person1);

    // Demonstrate using smart pointers (unique_ptr)
    auto person2 = std::make_unique<Person>();
    person2->name = "Jane Doe";
    person2->age = 28;
    person2->height = 1.65f;

    // Print the person's details
    printPerson(person2.get());

    // No need to manually delete smart pointers; they automatically clean up when they go out of scope

    return 0;
}
