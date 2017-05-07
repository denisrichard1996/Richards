#!/usr/bin/python3
#-*- coding: utf-8 -*-

from RotaSquare.Domain import *
from RotaSquare.GUI import *

class Game(object):

    def __init__(self):
        self.board = Board()
        self.player = 1
        self.round = 0
        self.win = 0
        self.interface = BashUserInterface(self)
        self.ref = Referee(self.board.tab)

    def change_player(self):
        self.player = 3-self.player

    def main(self):
        self.interface.display_init()
        while (self.win == 0):
            c = self.interface.input_turn()
            self.board.add(c, self.player)
            self.interface.display()
            self.win = self.ref.check_win(self.board.tab)
            self.change_player()
            self.round = (self.round + 1) % 3
            if (self.win == 0 and self.round == 0):
                self.board.rota()
                self.interface.display_rota()
                self.win = self.ref.check_win(self.board.tab)
        self.interface.display_win()
