#include <string>

#include "Notice.h"

using namespace std;

NoticeObserver::NoticeObserver() { }

NoticeObserver::~NoticeObserver() { }

NoticeBoard::NoticeBoard() { }

NoticeBoard::~NoticeBoard() 
{ 
	//delete(interestedParties);
}

void NoticeBoard::registerParty(NoticeObserver *observer)
{
	interestedParties.push_back(observer);
}

void NoticeBoard::newNotice(string notice)
{
	latestNotice = notice;
	cout << "NoticeBoard has recieved Notice \"" << notice << "\". Sending to all interested Observer parties ASAP" << endl;

	for (list<NoticeObserver*>::iterator iter = interestedParties.begin(); 
			iter != interestedParties.end(); iter++
		) 
	{
		(*iter)->notify(notice);
	}
}

