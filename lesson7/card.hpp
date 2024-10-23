#pragma once
#ifndef CARD_HPP
#define CARD_HPP


namespace CardGame {
	enum Suit {
		clubs = 0,
		diamonds = 1,
		hards = 2,
		spikes = 3
	};
	enum Ranks {
		two = 2,
		three,
		four,
		five,
		six,
		seven,
		eight,
		nine,
		ten,
		jack,
		queen,
		king,
		ace
	};
	class Card {
	public:
		Card() = default;
		Card(Ranks rank, Suit suit)
			:rank_(rank),
			suit_(suit)
		{}
		//геттеры делаем обязательно
		Suit GetSuit()const;
		Ranks GetRank()const;
	
		//сеттеры лучше не делать
	private:
		Ranks rank_;
		Suit suit_;
	};
}

#endif // !CARD_HPP