#pragma once
#include <iostream>
#include <list>

using namespace std;

class NoticeObserver {

	public:
		NoticeObserver();
		~NoticeObserver();
		virtual void notify(string message) = 0;
};

class NoticeBoard {

	public:
		NoticeBoard();
		~NoticeBoard();
		void registerParty(NoticeObserver *observer);
		void newNotice(string notice);

	private:
		string latestNotice;
		list<NoticeObserver*> interestedParties;
};