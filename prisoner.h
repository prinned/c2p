#pragma once
#include <iostream>
#include <vector>
#include <string>

//struct to return multiple vals
struct PD_results {
    std::vector<bool> history[2];
    int score[2];
    std::string name[2];
    int turns;
};

//abstract class to group everything
class Prisoner{
protected:
    std::string name;
    bool virtual react(std::vector<bool>& opturns) = 0;
public:
    std::string getName(){return name;}
    static PD_results fight(Prisoner& p1, Prisoner& p2, int total_turns = 10);
    static void Print(PD_results, std::string);
    std::string virtual getName() = 0;
};

// --------------------BOTS------------------------
// 1 | Always Defect
class Always_defect : public Prisoner {
protected:
    std::string name = "Always Defect";
public: 
    bool react(std::vector<bool>& opturns);
};

//2 | Always Co-operate
class Always_coop : public Prisoner {
protected:
    std::string name = "Always Co-op";
public: 
    bool react(std::vector<bool>& opturns);
};

//3 | Tit-for-Tat
class T4T : public Prisoner {
protected:
    std::string name = "Tit for Tat";
public:
    bool react(std::vector<bool>& opturns);
};

//4 | Grudger
class Grudger : public Prisoner {
protected:
    std::string name = "Grudger";
public:
    bool react(std::vector<bool>& opturns);
};

//5 | Suspicious Tit for Tat
class ST4T : public Prisoner {
protected:
    std::string name = "Suspicious Tit for Tat";
public:
    std::string getName(){return name;}
    bool react(std::vector<bool>& opturns);
};

//6 | Reverse Tit for Tat
class RT4T : public Prisoner {
protected:
    std::string name = "Rev. Tit-4-Tat";
public:
    std::string getName(){return name;}
    bool react(std::vector<bool>& opturns);
};

//7 | Prober
class Prober : public Prisoner {
protected:
    std::string name = "Prober";
public:
    std::string getName(){return name;}
    bool react(std::vector<bool>& opturns);
};


//8 | Athens
class Athens : public Prisoner {
protected:
    std::string name = "Athens";
public:
    std::string getName(){return name;}
    bool react(std::vector<bool>& opturns);
};


//9 | Tit-for-two-Tats
class T42T : public Prisoner {
protected:
    std::string name = "Tit-4-2-Tats";
public:
    std::string getName(){return name;}
    bool react(std::vector<bool>& opturns);
};

//10 | Generous T4T
class GT4T : public Prisoner {
protected:
    std::string name = "Generous T4T";
public:
    std::string getName(){return name;}
    bool react(std::vector<bool>& opturns);
};


//-------------------END-BOTS-----------------------
