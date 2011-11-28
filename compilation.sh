#!/bin/bash
gcc eth_lib.c -c
gcc write_eth_frame.c eth_lib.o -o write_eth_frame
gcc envoyer_trame.c eth_lib.o fonctions.c -o envois
gcc recevoir_trame.c eth_lib.o fonctions.c -o recevoir
gcc reponse_auto.c eth_lib.o fonctions.c -o reponse

