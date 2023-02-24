#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
using namespace std;

class Part {

public:
    virtual void getPart() = 0;
    virtual void addPart(Part* pr) { assert(false); }
    virtual ~Part() {}
};

class Wall : public Part
{
public:
    virtual void getPart() { cout<< "the wall is built" << endl; }
};
class Window : public Part
{
public:
    virtual void getPart() { cout <<  "the window is built" << endl; }
};
class Door : public Part
{
public:
    virtual void getPart() { cout << "the door is built" << endl; }
};

class CompositePart :public Part{

public:
    void getPart() {
        for (int i = 0; i < p.size(); i++)
        {
          p[i]->getPart();
        }
    }

    void addPart(Part* pr) { p.push_back(pr); }

    ~CompositePart() {
        for (int i = 0; i < p.size(); ++i)
            delete p[i];
    }
private:
    vector<Part*> p;
};

CompositePart* createHouse() {
    CompositePart* house = new CompositePart;
    for (int i = 0; i < 4; i++)
    {
        house->addPart(new Wall);
    }
    for (int i = 0; i < 8; i++)
    {
        house->addPart(new Window);
    }
    for (int i = 0; i < 1; i++)
    {
        house->addPart(new Door);
    }
    return house;
}

int main() {

    CompositePart* home = new CompositePart;
    for (int i = 0; i < 1; ++i)
        home->addPart(createHouse());
    cout << "House plan is: \n";
         home->getPart();
    delete home;

    return 0;
}