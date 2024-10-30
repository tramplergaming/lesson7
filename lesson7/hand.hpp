#pragma once
#ifndef HAND_HPP
#define HAND_HPP
#include <vector>
#include "Card.hpp"

namespace CardGame {

    class Hand {
    public:
        Hand() = default;
        Hand(const std::vector<CardGame::Card>& cards) : cards_(cards) {}

        CardGame::Card Show(int num) const;
        CardGame::Card GetCard(int num);

        void PlaceCard(const CardGame::Card& new_card);

        int size() const { return cards_.size(); }

        const std::vector<CardGame::Card>& getCards() const { return cards_; }
    private:
        std::vector<CardGame::Card> cards_;
    };
}
#endif