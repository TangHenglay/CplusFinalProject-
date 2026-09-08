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

class HorrorMovie : public Movie{
public:
    HorrorMovie(const string& title, const string& customer) :
    Movie(title, customer) {}

    void display() override {
        cout << "Type: Horror" << endl;
        Movie::display();
    }
};

class RomanceMovie : public Movie {
public:
    RomanceMovie(const string& title, const string& customer) :
    Movie(title, customer) {}

    void display() override {
        cout << "Type: Romance" << endl;
        Movie::display();
    }
};
vector<Movie*> movies;

void addMovie() {
    string title;
    string type;
    string customer;

    cin.ignore();
    cout << "\nEnter Movie Title:";
    getline(cin, title);

    cout << "Enter type:";
    getline(cin, type);

    cout << "Enter customer name:";
    getline(cin, customer);

    if(type == "Action") {
        movies.push_back(new ActionMovie(title, customer));
    }
    else if(type == "Comedy") {
        movies.push_back(new ComedyMovie(title, customer));
    }
    else if(type == "Horror") {
        movies.push_back(new HorrorMovie(title, customer));
    }
    else if(type == "Romance") {
        movies.push_back(new RomanceMovie(title, customer));
    }
    else {
        cout << "Invalid type!" << endl;
        return;
    }
    cout << "Movie added!" << endl;
}

void searchMovie() {
    string title;

    cin.ignore();
    cout << "\nEnter Movie Title:";
    getline(cin, title);

    for(Movie*movie : movies) {
        if(movie->getTitle() == title) {
            cout << "\nMovie Found!" << endl;
            movie->display();
            return;
        }
    }
    cout << "Movie not found!" << endl;
}
