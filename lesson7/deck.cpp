#include <iostream> 
#include <vector> 
#include <string> 
#include <random> 

// ����� ����� 
class Card {
public:
    std::string suit;   // ����� ����� 
    std::string rank;   // ���� ����� 

    Card(std::string s, std::string r) : suit(s), rank(r) {}

    // ����� ��� ����������� ����� 
    std::string toString() const {
        return rank + " of " + suit;
    }
};

// ����� ��� �������� ������ 
class Deck {
private:
    std::vector<Card> cards; // ������, �������� ����� 

public:
    // ����������� ��� �������� ������ 
    Deck() {
        // ��������� ������ ������� (��������, ��� ������) 
        std::string suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
        std::string ranks[] = { "2", "3", "4", "5", "6", "7", "8", "9",
                                "10", "Jack", "Queen", "King", "Ace" };

        for (const auto& suit : suits) {
            for (const auto& rank : ranks) {
                cards.emplace_back(suit, rank);
            }
        }
    }

    // ���������� (�� ����������, �� �������������) 
    ~Deck() {}

    // ���������� ��� ����� � ������ 
    std::vector<Card> getCards() const {
        return cards;
    }

    // ����� ��� �������� ����� �� ������ 
    bool removeCard(const Card& card) {
        for (auto it = cards.begin(); it != cards.end(); ++it) {
            if (it->suit == card.suit && it->rank == card.rank) {
                cards.erase(it);
                return true; // ����� ������� � ������� 
            }
        }
        return false; // ����� �� ������� 
    }

    // ����� ��� ������������� ������ 
    void shuffle() {
        std::random_device rd;
        std::mt19937 g(rd()); // Mersenne Twister 19937 ��������� ��������� ����� 
        std::shuffle(cards.begin(), cards.end(), g);
    }
};

// ����� ��� �������� ���� 
class Hand {
private:
    std::vector<Card> hand; // ������, �������� ����� � ���� 

public:
    // ����������� (�� ����������, �� �������������) 
    Hand() {}

    // ���������� (�� ����������, �� �������������) 
    ~Hand() {}

    // ����� ��� ���������� ����� � ���� 
    void addCard(const Card& card) {
        hand.push_back(card);
    }

    // ����� ��� �������� ���������� ����� �� ���� 
    bool removeCard(const Card& card) {
        for (auto it = hand.begin(); it != hand.end(); ++it) {
            if (it->suit == card.suit && it->rank == card.rank) {
                hand.erase(it);
                return true; // ����� ������� � ������� 
            }
        }
        return false; // ����� �� ������� 
    }

    // ����� ��� ��������� ���� � ���� 
    void showHand() const {
        std::cout << "Hand contains:\n";
        for (const auto& card : hand) {
            std::cout << card.toString() << std::endl;
        }
    }
};

int main() {
    // ������� ������ ���� 
    Deck deck;
    // ������������ ������ 
    deck.shuffle();

    // ������� ���� 
    Hand hand;

    // ��������� ��������� ����� � ���� 
    hand.addCard(deck.getCards()[0]); // ��������� ������ ����� 
    hand.addCard(deck.getCards()[1]); // ��������� ������ ����� 

    // ������������� ����� � ���� 
    hand.showHand();

    // ������� ���� ����� �� ���� 
    hand.removeCard(deck.getCards()[0]);

    // ������������� ����� � ���� ����� �������� 
    hand.showHand();

    return 0;
}