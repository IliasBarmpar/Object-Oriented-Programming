#include "Player.hpp"
#include <list>
#include <iostream>

Player :: Player(int p)	{
	shuffle();
	fillProvinces();
	pos = p;
}

GreenDeck Player :: giveGreenDeck() {
	return greendeck;
}

BlackDeck Player :: giveBlackDeck() {
	return blackdeck;
}

Hand Player :: giveHand() {
	return hand;
}

Provinces Player :: giveProvinces() {
	return provinces;
}

Holdings Player :: giveHoldings() {
	return holdings;
}

Army Player :: giveArmy() {
	return army;
}

void Player :: fillProvinces(){
	for(int i=1;i<=4;i++) provinces.addCard(1,blackdeck.giveCard());
}

void Player :: printProvinces(){
	provinces.print();
}

void Player :: shuffle(){
	blackdeck.shuffle();
	greendeck.shuffle();
}

void Player :: printPlayerStatistics(){
	hand.print();
	provinces.print();
	holdings.print();
}

void Player :: printArmy(){
	army.print();
}

int Player :: givePos(){
	return pos;
}

int Player :: getInitialDefence(){
	return holdings.getInitialDefence();
}
