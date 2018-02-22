/*
 * classified.cpp
 *
 *  Created on: Feb 22, 2018
 *      Author: bondar
 */
#include "classified.hpp"
#include "classified.gen.hpp"
#include <eoslib/db.hpp>

extern "C" {
	void init() {

	}

	void apply( uint64_t code, uint64_t action ) {
		if( code == N(classified) ) {
			if( action == N(newuser) ) {
				eosio::print("New user action\n");
				auto msg = eosio::current_message<new_user>();

				eosio::print("Check auth\n");
				require_auth(msg.account);

				bytes b = eosio::raw::pack(msg);

				eosio::print("Adding user\n");

				uint32_t success = store_i64( N(classified), N(users_table), (char*)b.data, b.len);
			} else if ( action == N(newclassified) ) {
				eosio::print("New classified action\n");
				auto msg = eosio::current_message<new_classified>();

				eosio::print("Check auth\n");
				require_auth(msg.account);

				bytes b = eosio::raw::pack(msg.value);

				uint32_t len = b.len;
				char * data = (char*)b.data;

				eosio::print("Adding classified...\n");
				uint32_t success = store_str( msg.account, N(classifieds_table), (char *)msg.uid.get_data(), msg.uid.get_size(), data, len);
			}
		}
	}
}



