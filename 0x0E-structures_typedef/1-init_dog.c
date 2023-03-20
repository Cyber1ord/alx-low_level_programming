#include <stdio.h>

struct dog {
    char *name;
    float age;
    char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner) {
    d->name = name;
    d->age = age;
    d->owner = owner;
}

int main() {
    struct dog my_dog;
    init_dog(&my_dog, "Fido", 2.5, "John");
    printf("Name: %s\nAge: %f\nOwner: %s\n", my_dog.name, my_dog.age, my_dog.owner);
    return 0;
}

