#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Movie {
private:
    string title;
    string customer;
    bool rented;

public:
    Movie() {
        title = "";
        customer = "";
        rented = false;
    }

    Movie(const string& title, const string& customer) {
        this->title = title;
        this->customer = customer;

        if (customer == "") {
            rented = false;
        } else {
            rented = true;
        }         
    }
    string getTitle() {
        return title;
    }

    string getCustomer() {
        return customer;
    }

    void setTitle(const string& title) {
        this->title = title;
    }

    void setCustomer(const string& customer) {
        this->customer = customer;

        if (customer == "") {
            rented = false;
        } else {
            rented = true;
        }
    }

    virtual void display() {
        cout << "Title: " << title << endl;
        cout << "Customer Name: " << customer << endl;

        if (rented) {
            cout << "Statued: Rented." << endl;
        } else {
            cout << "Status: Available." << endl;
        }
    }

    virtual ~Movie() {}
};

class ActionMovie : public Movie {
public:
    ActionMovie(const string& title, const string& customer) :
    Movie(title, customer) {}

    void display() override {
        cout << "Type: Action" << endl;
        Movie::display();
    }
};

class ComedyMovie : public Movie {
public:
    ComedyMovie(const string& title, const string& customer) :
    Movie(title, customer) {}

    void display() override {
        cout << "Type: Comedy" << endl;
        Movie::display();
    }
};