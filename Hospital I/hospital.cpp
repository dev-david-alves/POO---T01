#include "hospital.hpp"

void Hospital::addPatient(Patient patient) {
    if (patients.find(patient.getId()) != patients.end()) {
        throw "Patient already in hospital's list";
    }
    patients[patient.getId()] = patient;
}

void Hospital::addDoctor(Doctor doctor) {
    if (doctors.find(doctor.getId()) != doctors.end()) {
        throw "Doctor already in hospital's list";
    }
    doctors[doctor.getId()] = doctor;
}

void Hospital::removePatient(std::string id) {
    if (patients.find(id) == patients.end()) {
        throw "Patient not in hospital";
    }
    patients.erase(id);
}

void Hospital::removeDoctor(std::string id) {
    if (doctors.find(id) == doctors.end()) {
        throw "Doctor not in hospital";
    }
    doctors.erase(id);
}

void Hospital::tie(std::string doctorId, std::string patientId) {
    if (doctors.find(doctorId) == doctors.end()) {
        throw "Doctor not in hospital";
    }
    if (patients.find(patientId) == patients.end()) {
        throw "Patient not in hospital";
    }
    doctors[doctorId].addPatient(patients[patientId]);
    patients[patientId].addDoctor(doctors[doctorId]);
}

std::string Hospital::toString() {
    std::string result = "";

    for (auto it = patients.begin(); it != patients.end(); it++) {
        result += it->second.toString() + "\n";
    }

    for (auto it = doctors.begin(); it != doctors.end(); it++) {
        result += it->second.toString() + "\n";
    }

    return result;
}