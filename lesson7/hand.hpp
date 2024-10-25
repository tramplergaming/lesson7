#pragma once
#ifndef HAND_HPP
#define HAND_HPP

#include <vector>
#include "card.hpp"

namespace CardGame{

	class Hand {
	public:
		//����� �������� ������, ���������� ��� ��������� ����
	private:
		std::vector<Card> cards_;
	};
}
#endif 
