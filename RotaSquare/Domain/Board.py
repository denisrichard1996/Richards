#!/usr/bin/python3
#-*- coding: utf-8 -*-

class Board(object):

    def __init__(self):
        self.tab = [[0 for i in range(8)] for j in range(8)]

    def can_add(self, c):
        return (self.tab[7][c] == 0)

    def add(self, c, x):
        i = 0
        while (self.tab[i][c] != 0):
            i = i+1
        self.tab[i][c] = x

    def rota(self):
        t2 = self.tab
        self.tab = [[0 for i in range(8)] for j in range(8)]
        for old_l in range(8):
            for old_c in reversed(range(8)):
                if (t2[old_l][old_c] != 0):
                    self.add(old_l, t2[old_l][old_c])
