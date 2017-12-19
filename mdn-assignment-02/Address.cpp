#include "stdafx.h"

#include <iostream>
#include <sstream>
#include <string>

#include "Address.h"

using namespace std;

Address::Address(AddressType type) {
	mType = type;
}

Address* Address::newPermanentAddress() {
	return new Address(AddressType::PERMANENT);
}

Address* Address::newCurrentAddress() {
	return new Address(AddressType::CURRENT);
}

Address* Address::newOfficeAddress() {
	return new Address(AddressType::OFFICE);
}

Address* Address::withDoorNumber(string doorNo) {
	mDoorNum = doorNo;
	return this;
}

Address* Address::withStreet1(string street1) {
	mStreet1 = street1;
	return this;
}

Address* Address::withStreet2(string street2) {
	mStreet2 = street2;
	return this;
}

Address* Address::withCity(string city) {
	mCity = city;
	return this;
}

Address* Address::withPin(string pin) {
	mPin = pin;
	return this;
}

string Address::getAddressString() {
	stringstream ss;
	ss << "Door Num: " << mDoorNum << "\\n"
		<< mStreet1 << "\\n"
		<< mStreet2 << "\\n"
		<< "City : " << mCity << "\\n"
		<< "PIN: " << mPin;
	return ss.str();
}