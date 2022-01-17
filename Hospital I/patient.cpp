#include "patient.hpp"

//Link patients and doctors.
//Two doctors of the same specialty cannot be responsible for the same patient.
//The patient must not enter the doctor's list twice and vice versa.
//If the patient is already in the doctor's list, throw exception.
void Patient::addDoctor(Doctor doctor) {
    if (doctors.find(doctor.getId()) != doctors.end()) {
        throw "Doctor already in patient's list";
    }
    doctors[doctor.getId()] = doctor;
}

//Remove patient from doctor's list.
//If the patient is not in the doctor's list, throw exception.
void Patient::removeDoctor(std::string doctorId) {
    if (doctors.find(doctorId) == doctors.end()) {
        throw "Doctor not in patient's list";
    }
    doctors.erase(doctorId);
}

std::string Patient::getId() {
    return id;
}

std::string Patient::getDiagnosis() {
    return diagnosis;
}

vector<Doctor> Patient::getDoctors() {
    vector<Doctor> doctors;
    for (auto it = this->doctors.begin(); it != this->doctors.end(); it++) {
        doctors.push_back(it->second);
    }
    return doctors;
}

std::string Patient::toString() {
    // Pac: alvis:avc        Meds: []
    std::string result = "Pac: " + id + ":" + diagnosis + " Meds: [";
    for (auto it = doctors.begin(); it != doctors.end(); it++) {
        result += it->second.getId() + " ";
    }
    result += "]";

    return result;
}