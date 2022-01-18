#include <iostream>
#include <map>

class User {
    std::string username;
    // Inbox inbox;
    std::map<std::string, User*> followers;
    std::map<std::string, User*> following;
    public:
        // void sendTweet(Message * msg);
        User(const std::string& username) : username(username) {}
        void follow(User * other) {
            if (other == nullptr) {
                return;
            }
            if (following.find(other->username) == following.end()) {
                following.insert(std::make_pair(other->username, other));
                other->followers.insert(std::make_pair(this->username, this));
            }
        }
        void unfollow(std::string username) {
            auto it = following.find(username);
            if (it != following.end()) {
                User* other = it->second;
                following.erase(it);
                other->followers.erase(this->username);
            }
        }
        // void like(int twId);
        // Inbox& getInbox();
        friend std::ostream& operator<<(std::ostream& os, const User& user) {
            os << user.username << "\n";
            os << "  Seguidos: [ "; 
            for(auto it = user.following.begin(); it != user.following.end(); it++) {
                os << it->first << " ";
            }
            os << "]\n";
            os << "  Seguidores: [ "; 
            for(auto it = user.followers.begin(); it != user.followers.end(); it++) {
                os << it->first << " ";
            }
            os << "]\n";

            return os;
        }
};

int main(){
    User u1("goku");
    User u2("sara");
    User u3("tina");
    
    std::cout << u1;
    std::cout << u2;
    std::cout << u3;

    u1.follow(&u2);
    u1.follow(&u3);
    u2.follow(&u3);

    std::cout << u1;
    std::cout << u2;
    std::cout << u3;

    return 0;
}