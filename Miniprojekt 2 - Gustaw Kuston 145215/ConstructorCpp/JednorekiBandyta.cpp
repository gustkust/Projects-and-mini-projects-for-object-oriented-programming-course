#include "JednorekiBandyta.h"
#include <iostream>
//#include "Logger.h"


//basic constructor
gambling_machine::gambling_machine()
    : single_game_cost (nullptr),
    percent_of_cost_to_prize (nullptr),
    chance_of_winning (nullptr),
    prize_pool (nullptr),
    number_of_games_played (nullptr),
    how_much_money_is_there_in_the_machine (nullptr),
    machine_capacity (nullptr)
    {
        reset();
        std::cout << "Default constructor." << std::endl;
    }

//copy constructor
gambling_machine::gambling_machine(const gambling_machine &n) {
    single_game_cost = new double(*n.single_game_cost);
    percent_of_cost_to_prize = new double(*n.percent_of_cost_to_prize);
    chance_of_winning = new double(*n.chance_of_winning);
    prize_pool = new double(*n.prize_pool);
    number_of_games_played = new int(*n.number_of_games_played);
    how_much_money_is_there_in_the_machine = new double(*n.how_much_money_is_there_in_the_machine);
    machine_capacity = new double(*n.machine_capacity);
    std::cout << "Copy constructor." << std::endl;
}

//move constructor
gambling_machine::gambling_machine(gambling_machine&& x) {
    single_game_cost = x.single_game_cost;
    percent_of_cost_to_prize = x.percent_of_cost_to_prize;
    chance_of_winning = x.chance_of_winning;
    prize_pool = x.prize_pool;
    number_of_games_played = x.number_of_games_played;
    how_much_money_is_there_in_the_machine = x.how_much_money_is_there_in_the_machine;
    machine_capacity = x.machine_capacity;

    x.single_game_cost = nullptr;
    x.percent_of_cost_to_prize = nullptr;
    x.chance_of_winning = nullptr;
    x.prize_pool = nullptr;
    x.number_of_games_played = nullptr;
    x.how_much_money_is_there_in_the_machine = nullptr;
    x.machine_capacity = nullptr;
    std::cout << "Move constructor." << std::endl;
}

//conversion constructor
gambling_machine::gambling_machine(double pp)
{
    prize_pool = new double(pp);

    single_game_cost = nullptr;
    percent_of_cost_to_prize = nullptr;
    chance_of_winning = nullptr;
    number_of_games_played = nullptr;
    how_much_money_is_there_in_the_machine = nullptr;
    machine_capacity = nullptr;
    std::cout << "Conversion constructor." << std::endl;
}

//deconstructon
gambling_machine::~gambling_machine() {
    if (single_game_cost != nullptr) delete single_game_cost;
    if (percent_of_cost_to_prize != nullptr) delete percent_of_cost_to_prize;
    if (chance_of_winning != nullptr) delete chance_of_winning;
    if (prize_pool != nullptr) delete prize_pool;
    if (number_of_games_played != nullptr) delete number_of_games_played;
    if (how_much_money_is_there_in_the_machine != nullptr) delete how_much_money_is_there_in_the_machine;
    if (machine_capacity != nullptr) delete machine_capacity;
    std::cout << "Destructor." << std::endl;
}


void gambling_machine::set_sgc(double sgc) {
    start();
    std::cout << "SGC setter." << std::endl;
    single_game_cost = new double(sgc);
    stop();
}
void gambling_machine::set_poctp(double poctp) {
    start();
    std::cout << "POCTP setter." << std::endl;
    percent_of_cost_to_prize = new double(poctp);
    stop();
}
void gambling_machine::set_cow(double cow) { 
    start();
    std::cout << "COW setter." << std::endl;
    chance_of_winning = new double(cow);
    stop();
}
void gambling_machine::set_pp(double pp) {
    start();
    std::cout << "PP setter." << std::endl;
    prize_pool = new double(pp);
    stop();
}
void gambling_machine::set_nogp(int nogp) {
    start();
    std::cout << "NOGP setter." << std::endl;
    number_of_games_played = new int(nogp);
    stop();
}
void gambling_machine::set_mc(double mc) {
    start();
    std::cout << "MC setter." << std::endl;
    machine_capacity = new double(mc);
    stop();
}
void gambling_machine::set_hmmititm(double hmmititm) {
    start();
    std::cout << "HMMITITM setter." << std::endl;
    how_much_money_is_there_in_the_machine = new double(hmmititm);
    stop();
}

//getters
double gambling_machine::get_sgc() {
    start();
    std::cout << "SGC getter." << std::endl;
    return *single_game_cost;
    stop();
}
double gambling_machine::get_poctp() { 
    start();
    return *percent_of_cost_to_prize; 
    std::cout << "POCTP getter." << std::endl;
    stop();
}
double gambling_machine::get_pp() { 
    start();
    std::cout << "COW getter." << std::endl;
    return *prize_pool; 
    stop();
}
double gambling_machine::get_hmmititm() {
    start();
    return *how_much_money_is_there_in_the_machine; 
    std::cout << "MC getter." << std::endl;
    stop();
}
double gambling_machine::get_mc() { 
    start();
    std::cout << "PP getter." << std::endl;
    return *machine_capacity; 
    stop();
}

int gambling_machine::get_nogp() { 
    start();
    std::cout << "NOGP getter." << std::endl;
    return *number_of_games_played; 
    stop();
}

void gambling_machine::reset_nogp() {
    start();
    std::cout << "PP getter." << std::endl;
    number_of_games_played = 0;
    stop();
}
void gambling_machine::reload_machine(double cash_left) {
    start();
    double *tmp = &cash_left;
    how_much_money_is_there_in_the_machine = tmp;
    prize_pool = tmp;
    stop();
}

//game
double gambling_machine::game_win() {
    start();
    double what_you_won;
    double random = (rand() % 100);
    double result = random / 100;
    double what_goes_to_the_price = *percent_of_cost_to_prize / 100 * *single_game_cost;
    *how_much_money_is_there_in_the_machine += *single_game_cost;
    *prize_pool += what_goes_to_the_price;
    if (result < *chance_of_winning) {
        what_you_won = *prize_pool;
        *how_much_money_is_there_in_the_machine -= *prize_pool;
        prize_pool = 0;
        return what_you_won;
    }
    else
    {
        return 0;
    }
    stop();
}
