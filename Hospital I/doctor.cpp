#include "doctor.hpp"

//Link patients and doctors.
//Two doctors of the same specialty cannot be responsible for the same patient.
//The patient must not enter the doctor's list twice and vice versa.
//If the patient is already in the doctor's list, throw exception.
void Doctor::addPatient(Patient patient) {
    if (patients.find(patient.getId()) != patients.end()) {
        throw "Patient already in doctor's list";
    }
    patients[patient.getId()] = patient;
}

//Remove patient from doctor's list.
//If the patient is not in the doctor's list, throw exception.
void Doctor::removePatient(std::string patientId) {
    if (patients.find(patientId) == patients.end()) {
        throw "Patient not in doctor's list";
    }
    patients.erase(patientId);
}

// Getters

std::string Doctor::getId() {
    return id;
}

std::vector<Patient> Doctor::getPatients() {
    vector<Patient> patients;
    for (auto it = this->patients.begin(); it != this->patients.end(); it++) {
        patients.push_back(it->second);
    }
    return patients;
}

std::string Doctor::getSpecialty() {
    return specialty;
}

// Prints the doctor's information

std::string Doctor::toString() {
    //Med: bisturi:cirurgia Pacs: []
    std::string result = "Med: " + id + ":" + specialty + " Pacs: [";
    for (auto it = patients.begin(); it != patients.end(); it++) {
        result += it->second.getId() + " ";
    }
    result += "]";

    return result;
}