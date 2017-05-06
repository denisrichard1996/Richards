#!/usr/bin/python3
#-*- coding: utf-8 -*-

# import sys
# sys.path[:0] = ['../Domain']
# import Domain.Plateau
from Board import *
from UserInterface import *


class BashUserInterface(UserInterface):

    def __init__(self, g):
        UserInterface.__init__(self, g)

    def valueToChar(self, x):
        if x == 0:
            return ' '
        elif x == 1:
            return 'X'
        else:
            return 'O'

    def valid_input(self, x):
        if x.isdigit():
            if (int(x) in range(8)):
                return True
        return False

    def display_init(self):
        print("WELCOME TO ROTASQUARE")
        self.display()

    def display(self):
        s = "#========#\n"
        for t in reversed(self.game.board.tab):
            s = s + "|"
            for x in t:
                s = s + self.valueToChar(x)
            s = s + "|\n"
        s = s +  "#========#\n"
        print(s)

    def display_rota(self):
        x = input("Rotation ahead!")
        self.display()

    def input_turn(self):
        print("Au tour du joueur " + str(self.game.player))
        c = input("Colonne : ")
        while not (self.valid_input(c) and self.game.board.can_add(int(c))):
            c = input("Colonne : ")
        return int(c)

    def display_win(self):
        if (self.game.win == 1):
            print("PLAYER 1 WINS!")
        elif (self.game.win == 2):
            print("PLAYER 2 WINS!")
        elif (self.game.win == 3):
            print("DRAW!")    
