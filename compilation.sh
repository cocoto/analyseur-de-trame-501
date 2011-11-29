#!/bin/bash
mkdir bin
gcc src/eth_lib.c -c
gcc src/write_eth_frame.c eth_lib.o -o bin/write_eth_frame
gcc src/sniff.c eth_lib.o -o bin/sniff
gcc src/envoyer_trame.c eth_lib.o src/fonctions.c -o bin/envois
gcc src/recevoir_trame.c eth_lib.o src/fonctions.c -o bin/recevoir
gcc src/reponse_auto.c eth_lib.o src/fonctions.c -o bin/reponse
rm eth_lib.o
