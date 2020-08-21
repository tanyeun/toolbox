#include <cstdio>
#include <string>
using namespace std;

const string unk = "unknown";
const string clone_prefix = "clone-";

// -- interface --
class Animal {
    string _type = "";
    string _name = "";
    string _sound = "";
public:
    Animal();   // default constructor
    Animal(const string & type, const string & name, const string & sound);
    Animal(const Animal &); // copy constructor
    Animal & operator = (const Animal &); // copy operator
    ~Animal();  // destructor
    
    void print() const;
};

// -- implementation --
Animal::Animal() : _type(unk), _name(unk), _sound(unk) {
    puts("default constructor");
}

Animal::Animal(const string & type, const string & name, const string & sound)
: _type(type), _name(name), _sound(sound) {
    puts("constructor with arguments");
}

Animal::Animal(const Animal & rhs) {
    puts("copy constructor");
    _name = clone_prefix + rhs._name;
    _type = rhs._type;
    _sound = rhs._sound;
}

Animal::~Animal() {
    printf("destructor: %s the %s\n", _name.c_str(), _type.c_str());
}

void Animal::print () const {
    printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}

Animal & Animal::operator = (const Animal & rhs) {
    puts("copy operator");
    if(this != &rhs) {
        _name = clone_prefix + rhs._name;
        _type = rhs._type;
        _sound = rhs._sound;
    }
    return *this;
}

int main() {
    // default constructor
    Animal a;
    a.print();
    
    // constructor with arguments
    const Animal b("cat", "fluffy", "meow");
    b.print();
    
    // copy constructor
    const Animal c = b;
    c.print();
    
    // copy operator
    a = c;
    a.print();
    
    return 0;
}
