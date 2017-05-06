#!/usr/bin/python3
#-*- coding: utf-8 -*-

class Referee(object):

    def __init__(self, tab):
        self.full = True
        self.win1 = False
        self.win2 = False
        self.tab = tab

    def line(self, x, y):
        return self.tab[x][y]*self.tab[x+1][y]*self.tab[x+2][y]*self.tab[x+3][y]

    def column(self, x, y):
        return self.tab[x][y]*self.tab[x][y+1]*self.tab[x][y+2]*self.tab[x][y+3]

    def diagup(self, x, y):
        return self.tab[x][y]*self.tab[x+1][y+1]*self.tab[x+2][y+2]*self.tab[x+3][y+3]

    def diagdown(self, x, y):
        return self.tab[x+3][y]*self.tab[x+2][y+1]*self.tab[x+1][y+2]*self.tab[x][y+3]

    def check(self, val):
        if (val == 1):
            self.win1 = True
        elif (val == 16):
            self.win2 = True
        elif (val == 0):
            self.full = False

    def check_win(self, tab):
        self.full = True
        self.win1 = False
        self.win2 = False
        self.tab = tab

        for x in range(8):
            for y in range(8):
                if (x<5):
                    self.check(self.line(x,y))
                if (y<5):
                    self.check(self.column(x, y))
                if (x<5 and y<5):
                    self.check(self.diagdown(x, y))
                    self.check(self.diagup(x, y))
                if (self.win1 and self.win2):
                    return 3
        if self.win1:
            return 1
        if self.win2:
            return 2
        if self.full:
            return 3
        return 0
