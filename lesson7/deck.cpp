#include <iostream> 
#include <vector> 
#include <string> 
#include <random> 

// Класс карты 
class Card {
public:
    std::string suit;   // Масть карты 
    std::string rank;   // Ранг карты 

    Card(std::string s, std::string r) : suit(s), rank(r) {}

    // Метод для отображения карты 
    std::string toString() const {
        return rank + " of " + suit;
    }
};

// Класс для хранения колоды 
class Deck {
private:
    std::vector<Card> cards; // Вектор, хранящий карты 

public:
    // Конструктор для создания колоды 
    Deck() {
        // Заполняем колоду картами (например, для покера) 
        std::string suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
        std::string ranks[] = { "2", "3", "4", "5", "6", "7", "8", "9",
                                "10", "Jack", "Queen", "King", "Ace" };

        for (const auto& suit : suits) {
            for (const auto& rank : ranks) {
                cards.emplace_back(suit, rank);
            }
        }
    }

    // Деструктор (не обязателен, но рекомендуется) 
    ~Deck() {}

    // Возвращает все карты в колоде 
    std::vector<Card> getCards() const {
        return cards;
    }

    // Метод для удаления карты из колоды 
    bool removeCard(const Card& card) {
        for (auto it = cards.begin(); it != cards.end(); ++it) {
            if (it->suit == card.suit && it->rank == card.rank) {
                cards.erase(it);
                return true; // Карта найдена и удалена 
            }
        }
        return false; // Карта не найдена 
    }

    // Метод для перемешивания колоды 
    void shuffle() {
        std::random_device rd;
        std::mt19937 g(rd()); // Mersenne Twister 19937 генератор случайных чисел 
        std::shuffle(cards.begin(), cards.end(), g);
    }
};

// Класс для хранения руки 
class Hand {
private:
    std::vector<Card> hand; // Вектор, хранящий карты в руке 

public:
    // Конструктор (не обязателен, но рекомендуется) 
    Hand() {}

    // Деструктор (не обязателен, но рекомендуется) 
    ~Hand() {}

    // Метод для добавления карты в руку 
    void addCard(const Card& card) {
        hand.push_back(card);
    }

    // Метод для удаления конкретной карты из руки 
    bool removeCard(const Card& card) {
        for (auto it = hand.begin(); it != hand.end(); ++it) {
            if (it->suit == card.suit && it->rank == card.rank) {
                hand.erase(it);
                return true; // Карта найдена и удалена 
            }
        }
        return false; // Карта не найдена 
    }

    // Метод для просмотра карт в руке 
    void showHand() const {
        std::cout << "Hand contains:\n";
        for (const auto& card : hand) {
            std::cout << card.toString() << std::endl;
        }
    }
};

int main() {
    // Создаем колоду карт 
    Deck deck;
    // Перемешиваем колоду 
    deck.shuffle();

    // Создаем руку 
    Hand hand;

    // Добавляем некоторые карты в руку 
    hand.addCard(deck.getCards()[0]); // Добавляем первую карту 
    hand.addCard(deck.getCards()[1]); // Добавляем вторую карту 

    // Просматриваем карты в руке 
    hand.showHand();

    // Удаляем одну карту из руки 
    hand.removeCard(deck.getCards()[0]);

    // Просматриваем карты в руке после удаления 
    hand.showHand();

    return 0;
}