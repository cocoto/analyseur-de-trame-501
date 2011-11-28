#!/bin/bash
mkdir bin
gcc eth_lib.c -c
gcc write_eth_frame.c eth_lib.o -o bin/write_eth_frame
gcc envoyer_trame.c eth_lib.o fonctions.c -o bin/envois
gcc recevoir_trame.c eth_lib.o fonctions.c -o bin/recevoir
gcc reponse_auto.c eth_lib.o fonctions.c -o bin/reponse
rm eth_lib.o
