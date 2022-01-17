#include <iostream>
#include <map>
#include <vector>

class Patient;

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
        void addPatient(std::string patientId, std::string patientDiagnosis) {
            Patient patient(patientId, patientDiagnosis);

            if (patients.find(patient.getId()) != patients.end()) {
                throw "Patient already in doctor's list";
            }
            patients[patient.getId()] = patient;
        }

        //Remove patient from doctor's list.
        //If the patient is not in the doctor's list, throw exception.
        void removePatient(std::string patientId) {
            if (patients.find(patientId) == patients.end()) {
                throw "Patient not in doctor's list";
            }
            patients.erase(patientId);
        }

        // Getters

        std::string getId() {
            return id;
        }

        std::vector<Patient> getPatients() {
            std::vector<Patient> patients;
            for (auto it = this->patients.begin(); it != this->patients.end(); it++) {
                patients.push_back(it->second);
            }
            return patients;
        }

        std::string getSpecialty() {
            return specialty;
        }

        // Prints the doctor's information

        std::string toString() {
            //Med: bisturi:cirurgia Pacs: []
            std::string result = "Med: " + id + ":" + specialty + " Pacs: [";
            for (auto it = patients.begin(); it != patients.end(); it++) {
                result += it->second.getId() + " ";
            }
            result += "]";

            return result;
        }
};

class Patient{
    std::string patientId;
    std::string diagnosis;

    std::map<std::string, Doctor> doctors;

    public:
        Patient(std::string patientId, std::string diagnosis) : patientId(patientId), diagnosis(diagnosis) {}

        //Link patients and doctors.
        //Two doctors of the same specialty cannot be responsible for the same patient.
        //The patient must not enter the doctor's list twice and vice versa.
        //If the patient is already in the doctor's list, throw exception.
        void addDoctor(std::string doctorId, std::string doctorSpecialty) {
            Doctor doctor(doctorId, doctorSpecialty);

            if (doctors.find(doctor.getId()) != doctors.end()) {
                throw "Doctor already in patient's list";
            }
            doctors[doctor.getId()] = doctor;
        }

        //Remove patient from doctor's list.
        //If the patient is not in the doctor's list, throw exception.
        void removeDoctor(std::string doctorId) {
            if (doctors.find(doctorId) == doctors.end()) {
                throw "Doctor not in patient's list";
            }
            doctors.erase(doctorId);
        }

        std::string getId() {
            return id;
        }

        std::string getDiagnosis() {
            return diagnosis;
        }

        std::vector<Doctor> getDoctors() {
            std::vector<Doctor> doctors;
            for (auto it = this->doctors.begin(); it != this->doctors.end(); it++) {
                doctors.push_back(it->second);
            }
            return doctors;
        }

        std::string toString() {
            // Pac: alvis:avc        Meds: []
            std::string result = "Pac: " + id + ":" + diagnosis + " Meds: [";
            for (auto it = doctors.begin(); it != doctors.end(); it++) {
                result += it->second.getId() + " ";
            }
            result += "]";

            return result;
        }
};

class Hospital {
    std::map<std::string, Patient> patients;
    std::map<std::string, Doctor> doctors;

    public:
        Hospital();

        void addPatient(std::string patientId, std::string patientDiagnosis)) {
            Patient patient(patientId, patientDiagnosis);

            if (patients.find(patient.getId()) != patients.end()) {
                throw "Patient already in hospital's list";
            }
            patients[patient.getId()] = patient;
        }

        void addDoctor(std::string doctorId, std::string doctorSpecialty) {
            Doctor doctor(doctorId, doctorSpecialty);

            if (doctors.find(doctor.getId()) != doctors.end()) {
                throw "Doctor already in hospital's list";
            }
            doctors[doctor.getId()] = doctor;
        }

        void removePatient(std::string patientId) {
            if (patients.find(id) == patients.end()) {
                throw "Patient not in hospital";
            }
            patients.erase(id);
        }

        void removeDoctor(std::string doctorId) {
            if (doctors.find(id) == doctors.end()) {
                throw "Doctor not in hospital";
            }
            doctors.erase(id);
        }
        
        void tie(std::string doctorId, std::string patientId) {
            if (doctors.find(doctorId) == doctors.end()) {
                throw "Doctor not in hospital";
            }
            if (patients.find(patientId) == patients.end()) {
                throw "Patient not in hospital";
            }
            doctors[doctorId].addPatient(patients[patientId]);
            patients[patientId].addDoctor(doctors[doctorId]);
        }

        Patient getPatient(std::string patientId) {
            if (patients.find(patientId) == patients.end()) {
                throw "Patient not in hospital";
            }
            return patients[patientId];
        }

        Doctor getDoctor(std::string doctorId) {
            if (doctors.find(doctorId) == doctors.end()) {
                throw "Doctor not in hospital";
            }
            return doctors[doctorId];
        }

        std::string toString() {
            std::string result = "";

            for (auto it = patients.begin(); it != patients.end(); it++) {
                result += it->second.toString() + "\n";
            }

            for (auto it = doctors.begin(); it != doctors.end(); it++) {
                result += it->second.toString() + "\n";
            }

            return result;
        }
};

int main () {
    Hospital hospital;

    hospital.addPatient("fred", "fatura");
    hospital.addPatient("alvis", "avc");
    hospital.addPatient("goku", "hemorragia");
    hospital.addPatient("silva", "sinusite");

    hospital.addDoctor("bisturi", "cirurgia");
    hospital.addDoctor("snif", "alergologia");
    hospital.addDoctor("facada", "cirurgia");

    hospital.toString();

    return 0;
}