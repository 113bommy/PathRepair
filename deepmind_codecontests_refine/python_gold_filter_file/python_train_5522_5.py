#!/usr/bin/env python3
# coding: utf-8
import random


class Dice() :

    mask = {'N':(1,5,2,3,0,4), 'E':(3,1,0,5,4,2),
            'W':(2,1,5,0,4,3), 'S':(4,0,2,3,5,1)}
    way = ("N","E","W","S")

    def __init__(self, data):
        self.label = data

    def move(self, data):
        self.label = [self.label[idx] for idx in self.mask[data]]

    def get_up(self):
        return self.label[0]

    def compare(self, dice2):
        ok = False
        for i in range(1000):
            check = True
            for i2 in range(6):
                if self.label[i2] == dice2.label[i2] :
                    continue
                else:
                    check = False
                    break

            if check :
                ok = True
                break
            else:
                self.move(self.way[random.randint(0,1)])
        return ok

dice1 = Dice(input().split())
dice2 = Dice(input().split())

if dice1.compare(dice2) :
    print ("Yes")
else:
    print ("No")

