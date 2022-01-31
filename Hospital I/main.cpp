#include <iostream>
#include <map>
#include <vector>
#include <memory>

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

class IMedico;

class IPaciente {
    public:
        virtual void addMedico(IMedico *medico) = 0;
        virtual void removerMedico(std::string idMedico) = 0;

        virtual std::string getId() = 0;
        virtual std::string getDiagnostico() = 0;
        virtual std::map<std::string, IMedico*> getMedicos() = 0;
        virtual void toString() = 0;
};

class IMedico {
    public:
        virtual void addPaciente(IPaciente *paciente) = 0;
        virtual void removerPaciente(std::string idPaciente) = 0;

        virtual std::string getId() = 0;
        virtual std::string getClasse() = 0;
        virtual std::map<std::string, IPaciente*> getPacientes() = 0;
        virtual void toString() = 0;
};

class Paciente: public IPaciente {
    protected:
        std::string sender;
        std::string diagnostico;
        std::map<std::string, IMedico*> medicos;

    public:
        Paciente() {}
        Paciente(std::string sender, std::string diagnostico) : sender(sender), diagnostico(diagnostico) {}

        void addMedico(IMedico *medico) {
            if(medicos.find(medico->getId()) != medicos.end()) {
                throw MessageException("Medico ja existe");
            }

            medicos.insert(std::pair<std::string, IMedico*>(medico->getId(), medico));
        }

        void removerMedico(std::string idMedico) {
            if(medicos.find(idMedico) == medicos.end()) {
                throw MessageException("Medico nao existe");
            }

            medicos.erase(idMedico);
        }

        std::string getId() {
            return sender;
        }

        std::string getDiagnostico() {
            return diagnostico;
        }

        std::map<std::string, IMedico*> getMedicos() {
            return medicos;
        }

        void toString() {
            std::cout << "Pac: " << sender << ": " << diagnostico << " Meds: [ ";

            for (auto it = medicos.begin(); it != medicos.end(); ++it) {
                std::cout << it->first << " ";
            }

            std::cout << "]\n";
        }
};

class Medico: public IMedico {
    protected:
        std::string sender;
        std::string classe;
        std::map<std::string, IPaciente*> pacientes;

    public:
        Medico() {}
        Medico(std::string sender, std::string classe): sender(sender), classe(classe) {}

        void addPaciente(IPaciente *paciente) {
            if(pacientes.find(paciente->getId()) != pacientes.end()) {
                throw MessageException("Paciente ja existe");
            }

            pacientes.insert(std::pair<std::string, IPaciente*>(paciente->getId(), paciente));
        }

        void removerPaciente(std::string idPaciente) {
            if(pacientes.find(idPaciente) == pacientes.end()) {
                throw MessageException("Paciente nao existe");
            }

            pacientes.erase(idPaciente);
        }

        std::string getId() {
            return sender;
        }

        std::string getClasse() {
            return classe;
        }

        std::map<std::string, IPaciente*> getPacientes() {
            return pacientes;
        }

        void toString() {
            std::cout << "Med: " << sender << ": " << classe << " Pacs: [ ";

            for (auto it = pacientes.begin(); it != pacientes.end(); ++it) {
                std::cout << it->first << " ";
            }

            std::cout << "]\n";
        }
};

class Hospital {
    private:
        std::map<std::string, IPaciente*> pacientes;
        std::map<std::string, IMedico*> medicos;

    public:
        Hospital() {}

        void removerPaciente(std::string sender) {
            if(pacientes.find(sender) == pacientes.end()) {
                throw MessageException("Paciente nao existe");
            }

            pacientes.erase(sender);
        }

        void removerMedico(std::string sender) {
            if(medicos.find(sender) == medicos.end()) {
                throw MessageException("Medico nao existe");
            }

            medicos.erase(sender);
        }

        void addPaciente(IPaciente *paciente) {
            if(pacientes.find(paciente->getId()) != pacientes.end()) {
                throw MessageException("Paciente ja existe");
            }

            pacientes.insert(std::pair<std::string, IPaciente*>(paciente->getId(), paciente));
        }

        void addMedico(IMedico *medico) {
            if(medicos.find(medico->getId()) != medicos.end()) {
                throw MessageException("Medico ja existe");
            }

            medicos.insert(std::pair<std::string, IMedico*>(medico->getId(), medico));
        }

        void vincular(std::string nomeMedico, std::string nomePaciente) {
            std::string classe = medicos[nomeMedico]->getClasse();
            std::map<std::string, IMedico*> meds = pacientes[nomePaciente]->getMedicos();
        
            for (auto it = meds.begin(); it != meds.end(); ++it) {
                if (it->second->getClasse() == classe) {
                    throw MessageException("Paciente ja possui medico da mesma classe");
                    return;
                }
            }

            pacientes[nomePaciente]->addMedico(medicos[nomeMedico]);
            medicos[nomeMedico]->addPaciente(pacientes[nomePaciente]);
        }

        void toString() {
            for(auto it = pacientes.begin(); it != pacientes.end(); ++it) {
                it->second->toString();
            }

            for(auto it = medicos.begin(); it != medicos.end(); ++it) {
                it->second->toString();
            }
        }
};

int main () {
    try {
        Hospital hospital;

        hospital.addPaciente(new Paciente("fred", "fatura"));
        hospital.addPaciente(new Paciente("alvis", "avc"));
        hospital.addPaciente(new Paciente("goku", "hemorragia"));
        hospital.addPaciente(new Paciente("silva", "sinusite"));

        hospital.addMedico(new Medico("bisturi", "cirurgia"));
        hospital.addMedico(new Medico("snif", "alergologia"));
        hospital.addMedico(new Medico("facada", "cirurgia"));

        hospital.toString();
        std::cout << "\n";

        hospital.vincular("bisturi", "fred");
        hospital.vincular("bisturi", "alvis");
        hospital.vincular("bisturi", "goku");
        hospital.vincular("snif", "silva");
        hospital.vincular("snif", "alvis");
        // hospital.vincular("facada", "goku");

        hospital.toString();
    } catch (MessageException &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}