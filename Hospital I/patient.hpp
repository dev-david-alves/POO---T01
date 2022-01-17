#pragma once

#include "doctor.hpp"

class Patient {
    std::string id;
    std::string diagnosis;

    std::map<std::string, Doctor> doctors;

    public:
        Patient(std::string name, std::string diagnosis) : id(name), diagnosis(diagnosis) {}

        //Link patients and doctors.
        //Two doctors of the same specialty cannot be responsible for the same patient.
        //The patient must not enter the doctor's list twice and vice versa.
        //If the patient is already in the doctor's list, throw exception.
        void addDoctor(Doctor doctor);

        //Remove patient from doctor's list.
        //If the patient is not in the doctor's list, throw exception.
        void removeDoctor(std::string doctorId);

        std::string getId();

        std::string getDiagnosis();

        vector<Doctor> getDoctors();

        std::string toString();
};