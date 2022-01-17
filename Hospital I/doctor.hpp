#include <iostream>
#include <map>
#include <vector>

class Doctor {
    std::string id;
    std::string specialty;
    std::map<std::string, Patient> patients;

    public:
        Doctor(std::string name, std::string specialty) : id(name), specialty(specialty) {}
        
        //Link patients and doctors.
        //Two doctors of the same specialty cannot be responsible for the same patient.
        //The patient must not enter the doctor's list twice and vice versa.
        //If the patient is already in the doctor's list, throw exception.
        void addPatient(std::string patientId, std::string patientDiagnosis);
        //Remove patient from doctor's list.
        //If the patient is not in the doctor's list, throw exception.
        void removePatient(std::string patientId);
        // Getters

        std::string getId();

        std::vector<Patient> getPatients();

        std::string getSpecialty();

        // Prints the doctor's information

        std::string toString();
};