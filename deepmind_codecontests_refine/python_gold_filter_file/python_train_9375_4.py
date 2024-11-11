class Dice:

    __dSNWE ={'S': (4, 0, 2, 3, 5, 1) , 'N': (1, 5, 2, 3, 0, 4),
             'W': (2, 1, 5, 0, 4, 3), 'E': (3, 1, 0, 5, 4, 2)}

    def __init__(self, v): # v [Top, Front, Right, Left, Back, Bottom ]
        self.view = v


    def rotateDice(self, direction):
        self.view = [self.view[i] for i in Dice.__dSNWE[direction]]

d1 = Dice(list(map(int, input().split())))
for d in input():
    d1.rotateDice(d)
print(d1.view[0])