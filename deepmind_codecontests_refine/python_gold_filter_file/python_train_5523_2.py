import random


class Dice(object):
    def __init__(self):
        self.t = 1
        self.s = 2
        self.e = 3
        self.w = 4
        self.n = 5
        self.b = 6

    def __init__(self, faces):
        self.t = faces[0]
        self.s = faces[1]
        self.e = faces[2]
        self.w = faces[3]
        self.n = faces[4]
        self.b = faces[5]

    def roll(self, direct):
        if direct == 0:
            self.t, self.s, self.b, self.n = self.n, self.t, self.s, self.b
        elif direct == 1:
            self.t, self.w, self.b, self.e = self.e, self.t, self.w, self.b
        elif direct == 2:
            self.n, self.w, self.s, self.e = self.w, self.s, self.e, self.n

    def is_equal(self, dice):
        if self.t == dice.t and self.s == dice.s and self.e == dice.e and self.w == dice.w and self.n == dice.n and self.b == dice.b:
            return True
        else:
            return False

faces1 = list(map(int, input().split()))
dice1 = Dice(faces1)
faces2 = list(map(int, input().split()))
dice2 = Dice(faces2)

flag = False

for i in range(10000):
    dice2.roll(random.randint(0, 3))
    if dice1.is_equal(dice2):
        flag = True
        break

if flag:
    print('Yes')
else:
    print('No')

