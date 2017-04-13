#!/bin/sh

./one_test                &&
./option_test             &&
./placelooker_test        &&
./taghistory_test         &&
./regularworker_test      &&
./eventlooker_test        &&
./objectstarthandler_test &&
./objectendhandler_test   &&
./arraystarthandler_test  &&
./keyhandler_test         &&
./valuehandler_test       &&
./converthandler_test     &&
./converter_test          &&
./handler_test
