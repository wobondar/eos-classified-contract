/*
 * classified.hpp
 *
 *  Created on: Feb 22, 2018
 *      Author: bondar
 */
#include <eoslib/eos.hpp>
#include <eoslib/string.hpp>

struct user {
   eosio::string name;
};

struct classified {
   eosio::string name;
   eosio::string text;
};

/* @abi action newuser
 * @abi table
*/
struct new_user {
   eosio::name account;
   user value;
};


/* @abi action newclassified
 * @abi table
*/
struct new_classified {
   eosio::name account;
   eosio::string uid;
   classified value;
};

