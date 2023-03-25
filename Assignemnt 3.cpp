#include <string>
#include <iostream>
#include <queue>
using namespace std;

struct Appointment {
    int hours;
    int mins;
};

class Person {

private:
    std::string name;
    int id;
    int age;

public:
    Person() : name(""), id(0), age(0) {}

    virtual ~Person() {}

    void setName(const string& n) {
        name = n;
    }

    void setId(int i) {
        id = i;
    }

    void setAge(int a) {
        age = a;
    }

    string getName() const {
        return name;
    }

    int getId() const {
        return id;
    }

    int getAge() const {
        return age;
    }

};

class Customer : public Person {

private:
    int mechanicId;
    Appointment appointment;

public:
    Customer() : mechanicId(0), appointment({ 0, 0 }) {}

    void setMechanicId(int mechId) {
        mechanicId = mechId;
    }

    void setAppointment(const Appointment& appoint) {
        appointment = appoint;
    }

    int getMechanicId() const {
        return mechanicId;
    }

    Appointment getAppointment() const {
        return appointment;
    }

    bool operator<(const Customer& c) const {
        if (appointment.hours < c.appointment.hours) {
            return true;
        }
        else if (appointment.hours == c.appointment.hours) {
            return (appointment.mins < c.appointment.mins);
        }
        else
            return false;
    }

    bool operator>(const Customer& c) const {
       if (appointment.hours > c.appointment.hours) {
            return true;
        }
        else if (appointment.hours == c.appointment.hours) {
            return (appointment.mins > c.appointment.mins);
        }
        else
            return false;
    }

    bool operator==(const Customer& c ) const {
        return (appointment.hours == c.appointment.hours &&
            appointment.mins == c.appointment.mins);
    }
};
class Mechanic : public Person {

private:
    int counter;
    Appointment appointments[];

public:
    Mechanic() : counter(0) {}

    void setCounter(int counter) {
        counter = counter;
    }

    void setAppointments(const Appointment* appoint) {
        for (int i = 0; i < counter; ++i) {
            appointments[i] = appoint[i];
        }
    }

    int getCounter() const {
        return counter;
    }

    Appointment* getAppointments() {
        return appointments;
    }

    const Appointment* getAppointments() const {
        return appointments;
    }
    bool isAvailable(const Appointment& appointment) const {
        for (int i = 0; i < counter; ++i) {
            if (appointments[i].hours == appointment.hours && appointments[i].mins == appointment.mins) {
                // Mechanic is busy at the given appointment time
                return false;
            }
        }
        return true;
    }

};

template<typename T>
class Queue {

private:
    queue<T> queue;
public:
    Queue() {}

    void push(const T& v) {
        queue.push_back(v);
    }

    void pop() {
        queue.pop_front();
    }

};
