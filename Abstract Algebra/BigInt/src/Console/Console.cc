//
// Created by heimdall on 02.11.18.
//

#include <iostream>
#include <set>
#include <BigInt/BigInt.h>
#include "Console.h"
#include "Algorithms/Chineese.h"

void Console::run() {
    while(true){
        std::cout << ">";
        std::string keyword;
        std::cin >> keyword;



        std::set<std::string> num_binary = {"+","-","*","/","%","^"};
        std::set<std::string> bool_binary = {"<",">","==",">=","<=","!="};
        std::set<std::string> mod_binary = {"%+","%-", "%*", "%/", "%%", "%^"};

        if(keyword == "q") break;
        else if(keyword == "sqrt"){
            std::string s;
            std::cin >> s;
            BigInt lhs(s);
            std::cout << Algorithms::sqrt(lhs);
            std::cout << std::endl;
        }else if(keyword == "chineese"){
            int n;
            std::cin >> n;
            vector<pair<BigInt, BigInt>> v;
            for(int i = 0; i < n; i++){
                BigInt x, y;
                std::cin >> x >> y;
                v.push_back({x,y});
            }
            BigInt res = Algorithms::chineese(v);
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
            if(keyword == "^")res =  Algorithms::pow(lhs, rhs);
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
            BigInt x, lhs, rhs, res;
            cin >> x;
            Ring r(x);
            if(keyword == "%+")res =  r.add(lhs,rhs);
            if(keyword == "%-")res =  r.sub(lhs,rhs);
            if(keyword == "%*")res =  r.mul(lhs,rhs);
            if(keyword == "%/")res =  r.div(lhs,rhs);
            if(keyword == "%^")res =  r.pow(lhs, rhs);
        }else{
            continue;
        }
    }
}
