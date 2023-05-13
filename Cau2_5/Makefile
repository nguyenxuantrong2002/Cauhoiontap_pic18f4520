# MPLAB IDE generated this makefile for use with GNU make.
# Project: a.mcp
# Date: Mon May 01 10:43:23 2023

AS = MPASMWIN.exe
CC = mcc18.exe
LD = mplink.exe
AR = mplib.exe
RM = rm

a.cof : Untitled.o
	$(LD) /l"C:\MCC18\lib" "..\..\..\..\..\..\..\MCC18\lkr\18f4520.lkr" "Untitled.o" /z__MPLAB_BUILD=1 /z__MPLAB_DEBUG=1 /o"a.cof" /M"a.map" /W

Untitled.o : Untitled.c ../../../../../../../MCC18/h/delays.h ../../../../../../../MCC18/h/timers.h Untitled.c ../../../../../../../MCC18/h/p18f4520.h ../../../../../../../MCC18/h/p18cxxx.h
	$(CC) -p=18F4520 "Untitled.c" -fo="Untitled.o" -D__DEBUG -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

clean : 
	$(RM) "Untitled.o" "a.cof" "a.hex"

