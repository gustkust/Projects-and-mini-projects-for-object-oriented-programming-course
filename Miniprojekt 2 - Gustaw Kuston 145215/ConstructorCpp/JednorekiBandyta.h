#include <iostream>
#include "Logger.h"
#include "Stopper.h"
#ifndef JEDNOREKIBANDYTA_H
#define JEDNOREKIBANDYTA_H


class gambling_machine: public Logger, public Stopper
{
private:
    double* single_game_cost;
    double* percent_of_cost_to_prize;
    double* chance_of_winning;
    double* prize_pool;
    int* number_of_games_played;
    double* how_much_money_is_there_in_the_machine;
    double* machine_capacity;
public:
    gambling_machine();
    gambling_machine(const gambling_machine &n);
    gambling_machine(gambling_machine&& x);
    gambling_machine(double pp);
    ~gambling_machine();
    void set_sgc(double sgc);
    void set_poctp(double poctp);
    void set_cow(double cow);
    void set_pp(double pp);
    void set_nogp(int nogp);
    void set_mc(double mc);
    void set_hmmititm(double hmmititm);

    double get_sgc();
    double get_poctp();
    double get_pp();
    double get_hmmititm();
    double get_mc();

    int get_nogp();
    void reset_nogp();
    void reload_machine(double cash_left);

    double game_win();
};

#endif
