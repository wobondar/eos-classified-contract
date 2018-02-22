/*
 * classified.gen.hpp
 *
 *  Created on: Feb 22, 2018
 *      Author: bondar
 */
#pragma once
#include <eoslib/types.hpp>
#include <eoslib/datastream.hpp>
#include <eoslib/raw_fwd.hpp>

namespace eosio { namespace raw {

		template<typename Stream> inline void pack( Stream& s, const user& value ) {
		  raw::pack(s, value.name);
		}
		template<typename Stream> inline void unpack( Stream& s, user& value ) {
		  raw::unpack(s, value.name);
		}

		template<typename Stream> inline void pack( Stream& s, const classified& value ) {
		  raw::pack(s, value.name);
		  raw::pack(s, value.text);
		}
		template<typename Stream> inline void unpack( Stream& s, classified& value ) {
		  raw::unpack(s, value.name);
		  raw::unpack(s, value.text);
		}
	}
}
