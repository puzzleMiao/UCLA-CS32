#include <iostream>
#include "CardSet.h"
using namespace std;

CardSet::CardSet() {}

bool CardSet::add(ItemType cardNumber)
{
	return m_cardset.insert(cardNumber);
}

int CardSet::size() const 
{
	return m_cardset.size();
}

void CardSet::print() const 
{
	for (int i = 0; i < m_cardset.size(); i++) 
	{
		ItemType k;
		m_cardset.get(i, k);
		cout << k << endl;
	}
}