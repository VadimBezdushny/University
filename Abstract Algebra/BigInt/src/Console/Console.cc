//
// Created by heimdall on 02.11.18.
//

#include "Console.h"


#ifndef _COLORS_
#define _COLORS_

/* FOREGROUND */
#define RST  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define FRED(x) KRED x RST
#define FGRN(x) KGRN x RST
#define FYEL(x) KYEL x RST
#define FBLU(x) KBLU x RST
#define FMAG(x) KMAG x RST
#define FCYN(x) KCYN x RST
#define FWHT(x) KWHT x RST

#define BOLD(x) "\x1B[1m" x RST
#define UNDL(x) "\x1B[4m" x RST

#endif  /* _COLORS_ */


void Console::run() {
    std::cout << BOLD(FMAG("[+ - * / % ^ < > == <= >= !=]")) << " operand_1 operand_2\n";
    std::cout << BOLD(FMAG("[%+ %- %* %/ %^]")) << " module operand_1 operand_2\n";
    std::cout << BOLD(FMAG("sqrt")) << " operand\n";
    std::cout << BOLD(FMAG("chineese")) << " n   a_1 p_1   a_2 p_2   ...   a_n p_n\n";
    while(true){
        BigInt num = BigInt("38696309") * BigInt("65039389"), res = 1;
        map<BigInt, int> f = Algo::factorize(num);


        std::cout << ">";

        std::string keyword;
        std::cin >> keyword;
        std::set<std::string> num_binary = {"+","-","*","/","%","^"};
        std::set<std::string> bool_binary = {"<",">","==",">=","<=","!="};
        std::set<std::string> mod_binary = {"%+","%-", "%*", "%/", "%%", "%^"};
        try{
        if(keyword == "q") break;
        else if(keyword == "sqrt"){
            std::string s;
            std::cin >> s;
            BigInt lhs(s);
            std::cout << Algo::sqrt(lhs);
            std::cout << std::endl;
        }else if(keyword == "chineese"){
            int n;
            std::cin >> n;
            std::cout << std::endl << "Enter constraints" << std::endl;
            vector<pair<BigInt, BigInt>> v;
            for(int i = 0; i < n; i++){
                BigInt x, y;
                std::cin >> x >> y;
                v.push_back({x,y});
            }
            BigInt res = Algo::chineese(v);
            std::cout << res << std::endl;
        }else if(num_binary.count(keyword) || bool_binary.count(keyword)){
            BigInt res;
            bool bool_res;
            std::string slhs,srhs;
            std::cin >> slhs >> srhs;
            BigInt lhs(slhs), rhs(srhs);
            if(keyword == "+")res =  lhs + rhs;
            if(keyword == "-")res =  lhs - rhs;
            if(keyword == "*")res =  lhs * rhs;
            if(keyword == "/")res =  lhs / rhs;
            if(keyword == "%")res =  lhs % rhs;
            if(keyword == "^")res =  Algo::pow(lhs, rhs);
            if(num_binary.count(keyword)) std::cout << res;

            if(keyword == "<")bool_res = lhs < rhs;
            if(keyword == ">")bool_res = lhs > rhs;
            if(keyword == "==")bool_res = lhs == rhs;
            if(keyword == "<=")bool_res = lhs <= rhs;
            if(keyword == ">=")bool_res = lhs >= rhs;
            if(keyword == "!=")bool_res = lhs != rhs;
            if(bool_binary.count(keyword)) std::cout << ((bool_res?"true":"false"));
            std::cout << std::endl;
        }else if(mod_binary.count(keyword)){
            BigInt mod, lhs, rhs, res;
            cin >> mod >> lhs >> rhs;
            if(keyword == "%+")res =  Algo::addMod(lhs,rhs, mod);
            if(keyword == "%-")res =  Algo::subMod(lhs,rhs, mod);
            if(keyword == "%*")res =  Algo::mulMod(lhs,rhs, mod);
            if(keyword == "%/")res =  Algo::divMod(lhs,rhs, mod);
            if(keyword == "%^")res =  Algo::powMod(lhs, rhs, mod);
            std::cout << res << std::endl;
        }else{
            continue;
        }
        }catch(exception e){
            cout << "Error!" << std::endl;
        }

    }
}
