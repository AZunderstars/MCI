#include "Messenger.hpp"

using namespace std;

void Messenger::output_create_address_success(IP ip)
{
    cout << ip.get_name() << " " << ip.get_value() << " added to list" << endl;
}

void Messenger::print_address(IP ip, ostream &ostr)
{
    ostr << ip.get_name() << " " << ip.get_value() << endl;
}

void Messenger::output_print_addresses(vector<IP> IPs)
{
    cout << "Your addresses :" << endl;
    cout << "Name       Address" << endl;
    for (IP ip : IPs)
    {
        print_address(ip);
    }
}

void Messenger::output_print_addresses_with_type(vector<IP> IPs, string type)
{
    cout << "Your " << type << " addresses :" << endl;
    cout << "Name       Address" << endl;
    for (IP ip : IPs)
    {
        print_address(ip);
    }
}

void Messenger::output_print_address_groups(vector<AddressGroup *> address_groups)
{
    cout << endl;
    for (AddressGroup *ag : address_groups)
    {
        cout << ag->get_name() << " ";
        vector<IP> ag_addresses = ag->get_addresses();
        for (int i = 0; i < ag_addresses.size() - 1; i++)
        {
            cout << ag_addresses[i].get_name() << ", ";
        }
        cout << ag_addresses[ag_addresses.size() - 1].get_name() << endl;
    }
}

void Messenger::output_create_address_group_success(AddressGroup *address_group)
{
    cout << "addressGroup " << address_group->get_name() << " created" << endl;
}

void Messenger::output_add_to_address_group_success(AddressGroup *address_group, IP ip)
{
    cout << ip.get_name() << " add to " << address_group->get_name() << endl;
}

void Messenger::output_get_address_by_name(IP ip)
{
    print_address(ip);
}

void Messenger::output_export_file_success()
{
    cout << "export addresses successfully" << endl;
}

void Messenger::output_import_file_success()
{
    cout << "import addresses successfully" << endl;
}

void Messenger::output_create_address_fail(string value)
{
    cout << value << " is not valid" << endl;
}
