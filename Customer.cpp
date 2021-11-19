//
// Created by ellabeeri on 10/11/2021.
//
#include "Customer.h"
#include <vector>
#include <string>
#include <algorithm>

Customer::Customer(std::string c_name, int c_id):name(c_name),id(c_id) {

}

std::string Customer::getName() const {
    return name;
}

int Customer::getId() const {
    return id;
}



SweatyCustomer::SweatyCustomer(std::string name, int id) : Customer(name, id) {

}

std::vector<int> SweatyCustomer::order(const std::vector<Workout> &workout_options) {
    std::vector<int> output;
    for(int i=0;i<workout_options.size();i++)
    {
     if(workout_options[i].getType()==WorkoutType::CARDIO)
     {
         output.push_back(workout_options[i].getId());
     }
    }
    return  output;


}

std::string SweatyCustomer::toString() const {
    return std::string();
}

CheapCustomer::CheapCustomer(std::string name, int id) : Customer(name, id) {

}


std::vector<int> CheapCustomer::order(const std::vector<Workout> &workout_options) {
    std::vector<int> output;
    int tmpMin = std::min(cheapestWOIdByType(WorkoutType::ANAEROBIC, workout_options), cheapestWOIdByType(WorkoutType::CARDIO,workout_options));
    int min= std::min(tmpMin,cheapestWOIdByType(WorkoutType::MIXED,workout_options));
    if(min<std::numeric_limits<int>::max());
        output.push_back(min);
    return output;


}

std::string CheapCustomer::toString() const {
    return std::string();
}


HeavyMuscleCustomer::HeavyMuscleCustomer(std::string name, int id) : Customer(name, id) {
    std::vector<int> output;


}

std::vector<int> HeavyMuscleCustomer::order(const std::vector<Workout> &workout_options) {
    std::vector<int> output;
    std::vector<Workout> work;
    for (int i = 0; i < workout_options.size(); i++) {
        if (workout_options[i].getType() == WorkoutType::ANAEROBIC)
            work.push_back(workout_options[i]);
    }
    std::sort(work.begin(),work.end(),[] (Workout a, Workout b)
    {
        return  a.getPrice()>b.getPrice();
    });
    for (int i = 0;  i <work.size() ; ++i) {
        output.push_back(work[i].getId());

    }
    return output;
}


std::string HeavyMuscleCustomer::toString() const {
    return std::string();
}

FullBodyCustomer::FullBodyCustomer(std::string name, int id) : Customer(name, id) {

}

std::vector<int> FullBodyCustomer::order(const std::vector<Workout> &workout_options) {
    std::vector<int> output;
    int cheapestCardio=cheapestWOIdByType(WorkoutType::CARDIO,workout_options);
    if(cheapestCardio<std::numeric_limits<int>::max())
        output.push_back(cheapestCardio);
    int expensiveMix= expensiveWOIdByType(WorkoutType::MIXED,workout_options);
    if(expensiveMix>std::numeric_limits<int>::min())
        output.push_back(expensiveMix);
    int cheapestAnaerobic=cheapestWOIdByType(WorkoutType::ANAEROBIC,workout_options);
    if(cheapestAnaerobic<std::numeric_limits<int>::max())
        output.push_back(cheapestAnaerobic);


    return output;
}

std::string FullBodyCustomer::toString() const {
    return std::string();

}

int Customer::cheapestWOIdByType(WorkoutType type, const std::vector<Workout> &vector) {
    int cheapest = std::numeric_limits<int>::max();
    int cheapestID = std::numeric_limits<int>::max();
    for (int i = 0; i < vector.size(); ++i) {
        if ((vector[i].getPrice() < cheapest) && (vector[i].getType() == type)) {
            cheapest = vector[i].getPrice();
            cheapestID = vector[i].getId();
        }
    }
    return cheapestID;
}
int Customer::expensiveWOIdByType(WorkoutType type, const std::vector<Workout> &vector) {
    int expensive = std::numeric_limits<int>::max();
    int expensiveID = std::numeric_limits<int>::max();
    for (int i = 0; i < vector.size(); ++i) {
        if ((vector[i].getPrice() >expensive) && (vector[i].getType() == type)) {
            expensive = vector[i].getPrice();
            expensiveID = vector[i].getId();
        }
    }
    return expensiveID;

}
