#include <iostream>
using namespace std;

class Singleton {
private:
    static Singleton* instance;
    Singleton() 
    {
        cout << "Singleton created." << endl;
    }
public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* getInstance() 
    {
        if (instance == nullptr) 
        {
            instance = new Singleton();
        }
        return instance;
    }
    static void destroyInstance() 
    {
        delete instance;
        instance = nullptr;
        cout << "Singleton destroyed." << endl;
    }

    void someMethod() 
    {
        cout << "Singleton method called." << endl;
    }
};
Singleton* Singleton::instance = nullptr;

int main() 
{
    Singleton* s1 = Singleton::getInstance();
    s1->someMethod();
    Singleton::destroyInstance();
    Singleton* s2 = Singleton::getInstance();
    s2->someMethod();
    Singleton::destroyInstance();
}
