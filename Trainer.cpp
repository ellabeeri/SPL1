//
// Created by ellabeeri on 10/11/2021.
//

#include "Trainer.h"
#include "Studio.h"
#include "Customer.h"

int Trainer::getCapacity() const {
    return capacity;
}

void Trainer::addCustomer(Customer *customer) {
    customersList.push_back(customer);
    capacity--;
    //std::vector<int> workOutID = customer->order(Studio().getWorkoutOptions());

}

void Trainer::removeCustomer(int id) {
    customersList.pop_back();
    capacity++;
    if (customersList.empty())
        closeTrainer();
    for (int i = 0; i < orderList.size(); ++i) {
        if (orderList[i].first == id) {
            salary=salary-orderList[i].second.getPrice();
            orderList.erase(orderList.begin() + i);
        }


    }
}

Customer *Trainer::getCustomer(int id) {
    for (int i = 0; i < customersList.size(); ++i) {
        if (customersList[i]->getId() == id)
            return customersList[i];
    }
    return nullptr;
}

std::vector<Customer *> &Trainer::getCustomers() {
    return customersList;

}

std::vector<OrderPair> &Trainer::getOrders() {
    return orderList;
}


void
Trainer::order(const int customer_id, const std::vector<int> workout_ids, const std::vector<Workout> &workout_options) {

    for (int i = 0; i < workout_ids.size(); i++) {
        for (int j = 0; j < workout_options.size(); j++) {
            if (workout_options[j].getId() == workout_ids[i]) {
                OrderPair pairIdWorkout = std::make_pair(customer_id, workout_options[j]);
                salary=salary+pairIdWorkout.second.getPrice();
                orderList.push_back(pairIdWorkout);
            }
        }
    }

}

void Trainer::openTrainer() {
    open = true;
}

void Trainer::closeTrainer() {
    open = false;
    capacity--;
}

int Trainer::getSalary() {
    return salary;
}

bool Trainer::isOpen() {

    return open;
}

Trainer::Trainer(int t_capacity) : capacity(t_capacity), limitCapacity(t_capacity), open(false) {
    std::vector<Customer *> c;
    customersList = c;
    std::vector<OrderPair> a;
    orderList = a;
    salary = 0;

}
