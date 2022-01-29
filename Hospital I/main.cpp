#include <iostream>
#include <map>
#include <vector>

class MessageException : public std::exception {
   std::string message;
    public:
        MessageException(const std::string& message) : 
            message(message) {
        }
        const char* what() const noexcept override {
            return message.c_str(); 
        }
};

class doctor;
class Patient;
class hospital;

class Doctor {
    std::string id;
    std::string specialty;
    std::map<std::string, Patient*> patients;

    public:
        Doctor(std::string name, std::string specialty) : id(name), specialty(specialty) {}
        
        //Link patients and doctors.
        //Two doctors of the same specialty cannot be responsible for the same patient.
        //The patient must not enter the doctor's list twice and vice versa.
        //If the patient is already in the doctor's list, throw exception.
        void addPatient(Patient* patient) {
            if(patients.find(patient->getId()) != patients.end()) {
                throw std::runtime_error("Patient already in doctor's list");
            }
            
            patients.insert(std::pair<std::string, Patient*>(patient->getId(), patient));
        }

        //Remove patient from doctor's list.
        //If the patient is not in the doctor's list, throw exception.
        void removePatient(std::string patientId) {
            if(patients.find(patientId) == patients.end()) {
                throw std::runtime_error("Patient not in doctor's list");
            }
            
            patients.erase(patientId);
        }

        // Getters

        std::string getId() {
            return this->id;
        }

        std::string getSpecialty() {
            return this->specialty;
        }

        std::vector<Patient> getPatients() {
            std::vector<Patient> patients;
            for (auto it = this->patients.begin(); it != this->patients.end(); it++) {
                patients.push_back(it->second);
            }

            return patients;
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

    std::map<std::string, Doctor*> doctors;

    public:
        Patient(std::string patientId, std::string diagnosis) : patientId(patientId), diagnosis(diagnosis) {}

        //Link patients and doctors.
        //Two doctors of the same specialty cannot be responsible for the same patient.
        //The patient must not enter the doctor's list twice and vice versa.
        //If the patient is already in the doctor's list, throw exception.
        void addDoctor(Doctor* doctor) {
            if(doctors.find(doctor->getId()) != doctors.end()) {
                throw std::runtime_error("Doctor already in patient's list");
            }
            
            doctors.insert(std::pair<std::string, Doctor*>(doctor->getId(), doctor));
        }

        //Remove patient from doctor's list.
        //If the patient is not in the doctor's list, throw exception.
        void removeDoctor(std::string doctorId) {
            if (doctors.find(doctorId) == doctors.end()) {
                throw std::runtime_error("Doctor not in patient's list");
            }

            doctors.erase(doctorId);
        }

        std::string getId() {
            return this->id;
        }

        std::string getDiagnosis() {
            return this->diagnosis;
        }

        std::vector<Doctor> getDoctors() {
            std::vector<Doctor> doctors;

            for (auto it = this->doctors.begin(); it != this->doctors.end(); it++) {
                doctors.push_back(it->second);
            }

            return doctors;
        }

        std::string toString() {
            std::string result = "Pac: " + id + ":" + diagnosis + " Meds: [";
            for (auto it = doctors.begin(); it != doctors.end(); it++) {
                result += it->second.getId() + " ";
            }
            result += "]";

            return result;
        }
};

class Hospital {
    std::map<std::string, Patient*> patients;
    std::map<std::string, Doctor*> doctors;

    public:
        Hospital();

        void addPatient(std::string patientId, std::string patientDiagnosis)) {
            Patient* patient(patientId, patientDiagnosis);

            if(patients.find(patientId) != patients.end()) {
                throw std::runtime_error("Patient already in hospital");
            }

            patients.insert(std::pair<std::string, Patient*>(patientId, patient));
        }

        void addDoctor(std::string doctorId, std::string doctorSpecialty) {
            Doctor* doctor(doctorId, doctorSpecialty);

            if(doctors.find(doctorId) != doctors.end()) {
                throw std::runtime_error("Doctor already in hospital");
            }

            doctors.insert(std::pair<std::string, Doctor*>(doctorId, doctor));
        }

        void removePatient(std::string patientId) {
            if(patients.find(patientId) == patients.end()) {
                throw std::runtime_error("Patient not in hospital");
            }

            patients.erase(patientId);
        }

        void removeDoctor(std::string doctorId) {
            if(doctors.find(doctorId) == doctors.end()) {
                throw std::runtime_error("Doctor not in hospital");
            }

            doctors.erase(doctorId);
        }
        
        void tie(std::string doctorId, std::string patientId) {
            if(patients.find(patientId) == patients.end()) {
                throw std::runtime_error("Patient not in hospital");
            }

            if(doctors.find(doctorId) == doctors.end()) {
                throw std::runtime_error("Doctor not in hospital");
            }

            patients[patientId]->addDoctor(doctors[doctorId]);
            doctors[doctorId]->addPatient(patients[patientId]);
        }

        Patient* getPatient(std::string patientId) {
            if(patients.find(patientId) == patients.end()) {
                throw std::runtime_error("Patient not in hospital");
            }

            return patients[patientId];
        }

        Doctor* getDoctor(std::string doctorId) {
            if(doctors.find(doctorId) == doctors.end()) {
                throw std::runtime_error("Doctor not in hospital");
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

    // catch the exceptions

    try {
        Hospital hospital = new Hospital();

        hospital.addPatient("fred", "fatura");
        hospital.addPatient("alvis", "avc");
        hospital.addPatient("goku", "hemorragia");
        hospital.addPatient("silva", "sinusite");

        hospital.addDoctor("bisturi", "cirurgia");
        hospital.addDoctor("snif", "alergologia");
        hospital.addDoctor("facada", "cirurgia");

        hospital.toString();
    } catch (MessageException &e) {
        std::cout << e.what() << '\n';
    }

    return 0;
}