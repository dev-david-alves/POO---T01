#include "agenda.hpp"

int main() {
    Agenda agenda;

    Contact eva("eva");
    Contact ana("ana");
    Contact bia("bia");

    eva.addPhone(Phone("oio", "8585"));
    eva.addPhone(Phone ("cla", "9999"));
    ana.addPhone(Phone ("tim", "3434"));
    bia.addPhone(Phone ("viv", "5454"));

    agenda.addContact(eva);
    agenda.addContact(ana);
    agenda.addContact(bia);

    Contact ana2("ana");

    ana2.addPhone(Phone ("cas", "4567"));
    ana2.addPhone(Phone ("oio", "8754"));

    agenda.addContact(ana2);

    agenda.toString();

    agenda.rmPhone("ana", 0);

    agenda.toString();

    agenda.rmContact("bia");

    agenda.toString();
    
    Contact ava("ava");
    Contact rui("rui");
    Contact zac("zac");

    ava.addPhone(Phone("tim", "5454"));
    rui.addPhone(Phone ("viv", "2222"));
    rui.addPhone(Phone ("oio", "9991"));
    zac.addPhone(Phone ("rec", "3131"));

    agenda.addContact(ava);
    agenda.addContact(rui);
    agenda.addContact(zac);

    agenda.toString();

    agenda.printSearch(agenda.search("va"));
    agenda.printSearch(agenda.search("999"));

    return 0;
}