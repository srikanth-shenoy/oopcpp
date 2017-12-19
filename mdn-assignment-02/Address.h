#pragma once

#include <iostream>

using namespace std;

class Address {

	enum class AddressType { PERMANENT, CURRENT, OFFICE };

	public:
		static Address* newPermanentAddress();
		static Address* newCurrentAddress();
		static Address* newOfficeAddress();

		Address* withDoorNumber(string doorNo);
		Address* withStreet1(string street1);
		Address* withStreet2(string street2);
		Address* withCity(string city);
		Address* withPin(string pin);

		string getAddressString();

	private:
		Address(AddressType type);
		AddressType mType;
		string mDoorNum;
		string mStreet1;
		string mStreet2;
		string mCity;
		string mPin;
};
