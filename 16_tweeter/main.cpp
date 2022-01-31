#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <sstream>

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

class Message {
    int id;
    std::string username;
    std::string msg;
    std::set<std::string> likes;
    public:
        Message(int id, const std::string& username, const std::string& msg):
            id(id), username(username), msg(msg) {
        }

        int getId() const { 
            return id; 
        }
            
        void like(const std::string& username) {
            likes.insert(username);
        }

        friend std::ostream& operator<<(std::ostream& os, const Message& msg) {
            os << msg.id << ":" << msg.username << " (" << msg.msg << ")";

            if(!msg.likes.empty()) {
                os << " [ ";
                for(const auto& like : msg.likes) {
                    os << like << " ";
                }
                os << "]";
            }
            
            return os;
        }
};

class Inbox {
    std::map<int, Message*> unread;
    std::map<int, Message*> allMsgs;
    public:
        Inbox() {}

        void storeUnread(Message* tweet) {
            unread.insert(std::pair<int, Message*>(tweet->getId(), tweet));
        }

        void storeReaded(Message* tweet) {
            allMsgs.insert(std::pair<int, Message*>(tweet->getId(), tweet));
        }

        std::vector<Message*> getUnread() {
            std::vector<Message*> unreadMsgs;
            for (auto& msg : unread) {
                unreadMsgs.push_back(msg.second);
                allMsgs.insert(std::pair<int, Message*>(msg.first, msg.second));
            }
            unread.clear();
            return unreadMsgs;
        }

        std::vector<Message*> getAll() {
            std::vector<Message*> allMsgsVector;
            for (auto& msg : allMsgs) {
                allMsgsVector.push_back(msg.second);
            }
            return allMsgsVector;
        }

        Message* getTweet(int id) {
            auto it = allMsgs.find(id);
            if (it == allMsgs.end()) {
                throw MessageException("Message not found");
            }
            return it->second;
        }

        void toString() {
            for (auto& msg : this->getUnread()) {
                std::cout << *msg << "\n";
            }

            if(this->getUnread().empty()) {
                for (auto& msg : this->getAll()) {
                    std::cout << *msg << "\n";
                }
            }

            std::cout << "\n";
        }
};

class User {
    std::string username;
    Inbox inbox;
    std::map<std::string, User*> followers;
    std::map<std::string, User*> following;
    public:
        User(const std::string& username) : username(username) {}

        void follow(User * other) {
            if (following.find(other->username) == following.end()) {
                following.insert(std::pair<std::string, User*>(other->username, other));
                other->followers.insert(std::pair<std::string, User*>(username, this));
            }
        }

        void unfollow(std::string username) {
            auto it = following.find(username);
            if (it == following.end()) {
                throw MessageException("User not found");
            }
            auto it2 = it->second->followers.find(this->username);
            it->second->followers.erase(it2);
            following.erase(it);
        }

        void like(int twId) {
            Message* tweet = inbox.getTweet(twId);
            if(tweet == nullptr) {
                throw MessageException("Message not found");
            }

            tweet->like(username);
        }

        Inbox& getInbox() {
            return inbox;
        }

        void sendTweet(Message* msg) {
            inbox.storeUnread(msg);
            for (auto& follower : followers) {
                follower.second->getInbox().storeUnread(msg);
            }
        }
        
        void toString() {
            std::cout << username << "\n";
            std::cout << "  seguidos: [ ";
            for(auto& following : following) {
                std::cout << following.first << " ";
            }
            std::cout << "]\n";

            std::cout << "  seguidores: [ ";
            for(auto& follower : followers) {
                std::cout << follower.first << " ";
            }
            std::cout << "]\n";
        }
};

class Controller {
    std::map<std::string, std::shared_ptr<User>> users;
    std::map<int, std::shared_ptr<Message>> tweets;
    int nextTweetId { 0 };
    
    Message* createMsg(std::string username, std::string msg) {
        Message* tweet = new Message(nextTweetId, username, msg);
        tweets.insert(std::pair<int, std::shared_ptr<Message>>(nextTweetId, std::shared_ptr<Message>(tweet)));
        nextTweetId++;
        return tweet;
    }

    public:
        Controller() {}

        void addUser(std::string username) {
            if (users.find(username) != users.end()) {
                throw MessageException("User already exists");
            }
            users.insert(std::pair<std::string, std::shared_ptr<User>>(username, std::shared_ptr<User>(new User(username))));
        }

        User* getUser(std::string username) {
            auto it = users.find(username);
            if (it == users.end()) {
                throw MessageException("User not found");
            }
            return it->second.get();
        }

        void sendTweet(std::string username, std::string msg) {
            User* user = getUser(username);
            Message* tweet = createMsg(username, msg);
            user->sendTweet(tweet);
        }

        void toString() {
            for (auto& user : users) {
                user.second->toString();
            }
            std::cout << "\n";
        }
};

int main(){
    try {
        Controller ctrl;

        std::cout << "Caso (Adicionar usuario)\n";;

        ctrl.addUser("goku");
        ctrl.addUser("sara");
        ctrl.addUser("tina");
        
        ctrl.toString();

        std::cout << "Caso (Seguir)\n";

        ctrl.getUser("goku")->follow(ctrl.getUser("sara"));
        ctrl.getUser("goku")->follow(ctrl.getUser("tina"));
        ctrl.getUser("sara")->follow(ctrl.getUser("tina"));

        ctrl.toString();

        std::cout << "Caso (Enviar tweet)\n";

        ctrl.sendTweet("sara", "hoje estou triste");
        ctrl.sendTweet("tina", "ganhei chocolate");
        ctrl.sendTweet("sara", "partiu ru");
        ctrl.sendTweet("tina", "chocolate ruim");
        ctrl.sendTweet("goku", "internet maldita");

        std::cout << "Caso (Ver tweets)\n";

        ctrl.getUser("goku")->getInbox().toString();
        ctrl.getUser("tina")->getInbox().toString();
        ctrl.getUser("sara")->getInbox().toString();

        std::cout << "Caso (Curtir)\n";

        ctrl.getUser("sara")->like(1);
        ctrl.getUser("goku")->like(1);
        ctrl.getUser("sara")->like(3);

        ctrl.getUser("sara")->getInbox().toString();
        ctrl.getUser("goku")->getInbox().toString();
        ctrl.getUser("tina")->getInbox().toString();

        ctrl.getUser("goku")->unfollow("tina");

        ctrl.toString();

        ctrl.getUser("bruno")->getInbox().toString();
        ctrl.getUser("goku")->follow(ctrl.getUser("kuririm"));
        ctrl.getUser("sara")->like(4);

    } catch (MessageException &e) {
        std::cout << e.what() << '\n';
    }

    return 0;
}