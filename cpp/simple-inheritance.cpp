// simple-inheritance.cpp by Bill Weinman <http://bw.org/>
// 2018-10-08
#include <iostream>
#include <string>
using namespace std;

// Animal class (base)
class Animal {
    string _name;
    string _type;
    string _sound;
    // private constructor prevents construction of base class
    Animal(){}
    
    //friend class Dog;  // this will give Dog access to _name, _type, _sound

protected:
    // protected constructor for use by derived classes
    Animal ( const string & n, const string & t, const string & s )
    : _name(n), _type(t), _sound(s) {}
public:
    virtual void speak() const;
    const string & name() const { return _name; }
    const string & type() const { return _type; }
    const string & sound() const { return _sound; }
};

void Animal::speak() const {
    printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}

// Dog class - derived from Animal
class Dog : public Animal {
    int _walked;
public:
    Dog( string n ) : Animal(n, "dog", "woof"), _walked(0) {};
    int walk() { return ++_walked; }
    void bark(int times);
    void speak() const { Animal::speak(); puts("Dog is barking.... again"); }
};

// This need friend to Animal class
//void Dog::bark(int times){
//
//    for(int i = 0; i < times; i++){
//        cout << _name << " barked " << _sound << endl; 
//    }
//
//}

// Cat class - derived from Animal
class Cat : public Animal {
    int _petted;
public:
    Cat( string n ) : Animal(n, "cat", "meow"), _petted(0) {};
    int pet() { return ++_petted; }
};

// Pig class - derived from Animal
class Pig : public Animal {
    int _fed;
public:
    Pig( string n) : Animal(n, "pig", "oink"), _fed(0) {};
    int feed() { return ++_fed; }
};

int main() {
    Dog d("Rover");
    Cat c("Fluffy");
    Pig p("Arnold");
    
    d.speak();
    c.speak();
    p.speak();
    
    cout << "the " << d.type() << " has been walked " << d.walk() << " times" << endl;
    cout << "the " << c.type() << " has been petted " << c.pet() << " times" << endl;
    cout << "the " << p.type() << " has been fed " << p.feed() << " times" << endl;

    //d.bark(3);
    
    // although d,c,p are references to it's own derived classe
    // but ap is of type Animal, so it will run Animal::speak
    // unless you declaed it as virtual
    Animal * ap[] = {&d, &c, &p};
    for( auto ptr : ap ){
        ptr->speak();
    }
    
}
