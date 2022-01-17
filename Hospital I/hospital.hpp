#pragma once

#include "patient.hpp"
#include "doctor.hpp"

class Hospital {
    std::map<std::string, Patient> patients;
    std::map<std::string, Doctor> doctors;

    public:
        Hospital();

        void addPatient(Patient patient);

        void addDoctor(Doctor doctor);

        void removePatient(std::string id);

        void removeDoctor(std::string id);
        
        void tie(std::string doctorId, std::string patientId);

        std::string toString();
}