#!/usr/bin/python3
#-*- coding: utf-8 -*-

from Domain import *
from GUI import *


class Game(object):

    def __init__(self):
        self.board = Board()
        self.player = 1
        self.round = 0
        self.win = 0
        self.interface = TkinterUserInterface(self)
        self.ref = Referee(self.board.tab)

    def change_player(self):
        self.player = 3-self.player

    def main(self):
        self.interface.display_init()
        self.interface.wait_input()

    def resume_main(self, c):
            self.board.add(c, self.player)
            self.interface.display()
            self.win = self.ref.check_win(self.board.tab)
            self.change_player()
            self.round = (self.round + 1) % 3
            if (self.win == 0 and self.round == 0):
                self.board.rota()
                self.interface.display_rota()
                self.win = self.ref.check_win(self.board.tab)
            if (self.win != 0):
                self.interface.display_win()
            else:
                self.interface.wait_input()
