#include <iostream>
#include <vector>
#include <string>
#include "prisoner.h"

//--------------------PRINTING-RESULTS--------------------
void Prisoner::Print(PD_results result, std::string custom, char coop_symbol, char defect_symbol){
    //printing turn history
    if (custom == "history" || custom == "h" || custom == ""){
        std::cout<<'\n'<<result.name[0]<<"\t |";
        for (bool i : result.history[0]) std::cout<<' '<<(i?coop_symbol:defect_symbol);
        std::cout<<'\n'<<result.name[1]<<"\t |";
        for (bool i : result.history[1]) std::cout<<' '<<(i?coop_symbol:defect_symbol);
        std::cout<<'\n';
    }
    if(custom == "score" || custom == "s" || custom == ""){
        std::cout<<result.name[0]<<"\t- "<<result.score[0]<<'\n'
                 <<result.name[1]<<"\t- "<<result.score[1]<<'\n';
    }
    std::cout<<'\n';
}
//----------------------END-PRINTING----------------------

//--------------------SIMULTING-FIGHT---------------------
PD_results Prisoner::fight(Prisoner& p1, Prisoner& p2, int total_turns){
    std::vector<bool> p1_turns;
    std::vector<bool> p2_turns;
    for (int i = 0; i < total_turns; i++){
        bool new_move = p1.react(p2_turns);
        p2_turns.push_back(p2.react(p1_turns)); 
        p1_turns.push_back(new_move);
    }

    //score calculation
    int p1_score = 0;
    int p2_score = 0;
    for (int i = 0; i < total_turns;i++){
        //both cooperate
        if (p1_turns[i] == true && p2_turns[i] == true){
            p1_score += 6;
            p2_score += 6;
        } 
        //both cheat
        else if(p1_turns[i] == false && p2_turns[i] == false){
            p1_score += 2;
            p2_score += 2;
        }
        //one cheats, one co-op
        else if(p1_turns[i] == true && p2_turns[i] == false){
            p2_score += 10;
        } else if(p1_turns[i] == false && p2_turns[i] == true){
            p1_score += 10;
        }
    } 
    
    //packing results and returning
    PD_results Return_vals;
    Return_vals.history[0] = p1_turns;
    Return_vals.history[1] = p2_turns;
    Return_vals.score[0] = p1_score;
    Return_vals.score[1] = p2_score;
    Return_vals.name[0] = p1.getName();
    Return_vals.name[1] = p2.getName();
    Return_vals.turns = total_turns;
    return Return_vals;
}
//-----------------END_SIMULATION-------------------

// --------------------BOTS------------------------
// 1 | Always Defect

bool inline Always_defect::react(std::vector<bool>& opturns){
    return 0;
}

//2 | Always Co-operate
bool inline Always_coop::react(std::vector<bool>& opturns){
    return 1;
}

//3 | Tit-for-Tat
bool T4T::react(std::vector<bool>& opturns){
    if (opturns.size() == 0) return 1;
    return opturns.back();
}

//4 | Grudger
bool Grudger::react(std::vector<bool>& opturns){
    if (opturns.size() == 0) return true;
    for (auto i : opturns){
        if (i == false) return false;
    }
}

//5 | Suspicious Tit for Tat
bool ST4T::react(std::vector<bool>& opturns){
    if (opturns.size() == 0) return 0;
    return opturns.back();
}

//6 | Reverse Tit for Tat
bool RT4T::react(std::vector<bool>& opturns){
    if (opturns.size() == 0) return 0;
    return !(opturns.back());
}

//7 | Prober
bool Prober::react(std::vector<bool>& opturns){
    if (opturns.size() == 0) return false;
    if (opturns.size() == 1 || opturns.size() == 2) return true;
    if (opturns[1] == true && opturns[2] == true) return false; 
    return opturns.back();
}


//8 | Athens
//nvm 

//9 | Tit-for-two-Tats
bool T42T::react(std::vector<bool>& opturns){
    if (opturns.size() == 0) return true;
    if (opturns.back() == false || opturns[opturns.size() - 1] == false)return false;
    return false;
}

//10 | Generous T4T
bool GT4T::react(std::vector<bool>& opturns){
    if (opturns.size() == 0) return true;
    if (opturns.back() == false && opturns[opturns.size() - 1] == false)return false;
    return true;
}

//-------------------END-BOTS-----------------------