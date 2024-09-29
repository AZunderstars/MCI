#include "Messenger.hpp"

using namespace std;

void Messenger::output_create_address_success(Address address)
{
    cout << address.get_name() << " " << address.get_ip_value() << " added to list" << endl;
}

void Messenger::print_address(Address address, ostream &ostr)
{
    ostr << address.get_name() << " " << address.get_ip_value() << endl;
}

void Messenger::output_print_addresses(vector<Address> addresses)
{
    cout << "Your addresses :" << endl;
    cout << "Name       Address" << endl;
    for (Address address : addresses)
    {
        print_address(address);
    }
}

void Messenger::output_print_addresses_with_type(vector<Address> addresses, string type)
{
    cout << "Your " << type << " addresses :" << endl;
    cout << "Name       Address" << endl;
    for (Address address : addresses)
    {
        print_address(address);
    }
}

void Messenger::output_print_address_groups(vector<AddressGroup *> address_groups)
{
    cout << endl;
    for (AddressGroup *ag : address_groups)
    {
        cout << ag->get_name() << " ";
        vector<Address> ag_addresses = ag->get_addresses();
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

void Messenger::output_add_to_address_group_success(AddressGroup *address_group, Address address)
{
    cout << address.get_name() << " add to " << address_group->get_name() << endl;
}

void Messenger::output_get_address_by_name(Address address)
{
    print_address(address);
}

void Messenger::output_export_file_success()
{
    cout << "export addresses successfully" << endl;
}

void Messenger::output_import_file_success()
{
    cout << "import addresses successfully" << endl;
}

void Messenger::output_create_address_fail(string ip_value)
{
    cout << "error " << ip_value << " is not valid" << endl;
}

void Messenger::output_address_group_not_found(string name)
{
    cout << "error " << name << " is not available" << endl;
}

void Messenger::output_address_not_found(std::string name)
{
    cout << "error " << name << " is not available" << endl;
}

void Messenger::output_address_already_in_address_group(AddressGroup *address_group, Address address)
{
    cout << "error " << address.get_name() << " is already in " << address_group->get_name() << endl;
}
