#!/usr/bin/env python3
# coding: utf-8

class Dice() :
    rightlist = ((-1,3,1,4,2,-1),
                 (2,-1,5,0,-1,3),
                 (4,0,-1,-1,5,2),
                 (1,5,-1,-1,0,4),
                 (3,-1,0,5,-1,2),
                 (-1,2,4,1,3,-1))

    def __init__(self, data):
        self.label = data

    def get_up(self):
        return self.label[0]

    def get_rightdata(self, up, front):
        upidx = self.label.index(up);
        fridx = self.label.index(front)
        return self.label[self.rightlist[fridx][upidx]]


dicedata = input().split()
count = int(input())
queslist = []
[queslist.append(input().split()) for i in range(count)]

newdice = Dice(dicedata)

[print(newdice.get_rightdata(queslist[i][0], queslist[i][1])) for i in range(count)]



