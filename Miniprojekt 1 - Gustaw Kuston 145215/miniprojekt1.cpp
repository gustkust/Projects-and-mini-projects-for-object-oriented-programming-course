#include <iostream>
#include <ctime>


class gambling_machine {

private:
    double single_game_cost;
    double percent_of_cost_to_prize; //that goes to the prize
    double chance_of_winning;
    double prize_pool;
    int number_of_games_played;
    double how_much_money_is_there_in_the_machine;
    double machine_capacity;

public:
    void set_sgc(double sgc) { single_game_cost = sgc; } //sets new single game cost
    double get_sgc() { return single_game_cost; } //gets current single game cost
    void set_poctp(double poctp) { percent_of_cost_to_prize = poctp; } //sets new percent of game cost that goes to the game prize
    void set_cow(double cow) { chance_of_winning = cow; } //sets new chance of winning
    double get_poctp() { return percent_of_cost_to_prize; } //gets current percent of game cost that goes to the game prize
    double get_pp() { return prize_pool; } // gets current prize pool
    int get_nogp() { return number_of_games_played; } //gets number of played games
    void reset_nogp() { number_of_games_played = 0; } //resets number of games played
    double get_hmmititm() { return how_much_money_is_there_in_the_machine; } //gets current amount of money in the machine
    double get_mc() { return machine_capacity; } //gets machine capacity
    void set_mc(double mc) { machine_capacity = mc; } //sets new machine capacity
    void reload_machine(double cash_left) { //withdraws money from machine (but leaves given amount of money for the prize)
        how_much_money_is_there_in_the_machine = cash_left;
        prize_pool = cash_left;
    }
    void set_pp(double pp) { prize_pool = pp; } //sets new prize pool
    double game_win() { //plays out the gane
        double what_you_won;
        double random = (rand() % 100);
        double result = random / 100;
        double what_goes_to_the_price = percent_of_cost_to_prize / 100 * single_game_cost;
        how_much_money_is_there_in_the_machine += single_game_cost;
        prize_pool += what_goes_to_the_price;
        if (result < chance_of_winning) {
            what_you_won = prize_pool;
            how_much_money_is_there_in_the_machine -= prize_pool;
            prize_pool = 0;
            return what_you_won;
        }
        else
        {
            return 0;
        }
    }
};


int main() {
    srand(time(NULL));
    gambling_machine machine;
    machine.set_sgc(10);
    machine.set_poctp(50);
    machine.set_cow(0.15);
    machine.set_mc(2000);
    machine.set_pp(500);
    machine.reload_machine(500);
    machine.reset_nogp();
    std::cout << "Loaded basic settings." << std::endl;

    bool end = false;
    int option;
    while (end == false) {
        std::cout << "\nChoose option number:" << std::endl;
        std::cout << "1. Play the game." << std::endl;
        std::cout << "2. Check single game cost." << std::endl;
        std::cout << "3. Check the prize pool." << std::endl;
        std::cout << "4. Check percent of single game cost that goes to the price." << std::endl;
        std::cout << "5. Check how much money is there in the machine." << std::endl;
        std::cout << "6. Set new single game cost." << std::endl;
        std::cout << "7. Set new percent of single game cost that goes to the price." << std::endl;
        std::cout << "8. Set new machine capacity." << std::endl;
        std::cout << "9. Reload the machine." << std::endl;
        std::cout << "0. End program." << std::endl;
        if (machine.get_hmmititm() > machine.get_mc()) {
            std::cout << "Warning! The machine is full." << std::endl;
        }
        std::cin >> option;
        double result;
        switch (option) {
        case 1:
            result = machine.game_win();
            if (result == 0) {
                std::cout << "You have lost!" << std::endl;
            }
            else {
                std::cout << "You have won " << result << " cash!" << std::endl;
            }
            break;
        case 2:
            std::cout << "The value is: " << std::endl;
            double sgc;
            sgc = machine.get_sgc();
            std::cout << sgc << std::endl;
            break;
        case 3:
            std::cout << "The value is: " << std::endl;
            double pp;
            pp = machine.get_pp();
            std::cout << pp << std::endl;
            break;
        case 4:
            std::cout << "The value is: " << std::endl;
            double poctp;
            poctp = machine.get_poctp();
            std::cout << poctp << std::endl;
            break;
        case 5:
            std::cout << "The value is: " << std::endl;
            double hmmititm;
            hmmititm = machine.get_hmmititm();
            std::cout << hmmititm << std::endl;
            break;
        case 6:
            std::cout << "Enter new cost:" << std::endl;
            double nsgc;
            std::cin >> nsgc;
            machine.set_sgc(nsgc);
            break;
        case 7:
            std::cout << "Enter new percent (1 - 70):" << std::endl;
            double npoctp;
            std::cin >> npoctp;
            if (npoctp > 70 or npoctp < 1) {
                std::cout << "Wrong value." << std::endl;
            }
            else {
                machine.set_poctp(npoctp);
                std::cout << "Done." << std::endl;
            }
            break;
        case 8:
            std::cout << "Enter new machine capacity:" << std::endl;
            double nmc;
            std::cin >> nmc;
            machine.set_mc(nmc);
            std::cout << "Done." << std::endl;
            break;
        case 9:
            std::cout << "How much money do you want to leave for the prize?:" << std::endl;
            double np;
            std::cin >> np;
            if (np > machine.get_hmmititm()) {
                std::cout << "Wrong value." << std::endl;
            }
            else {
                machine.reload_machine(np);
                std::cout << "Done." << std::endl;
            }
            break;
        case 0:
            end = true;
            break;
        }
    }
    return 0;
}