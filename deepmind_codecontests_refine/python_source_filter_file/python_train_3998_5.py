import math
import re
from fractions import Fraction
from collections import Counter

class Task:
    worms = []
    answer = ''
    
    def __init__(self):
        input()
        self.worms = [int(x) for x in input().split()]

    def solve(self):
        worms = self.worms
        for i in range(0, len(worms)):
            for j in range(0, len(worms)):
                for k in range(0, len(worms)):
                    if worms[i] + worms[j] == worms[k]:
                        self.answer = str(i + 1) + ' ' + str(j + 1) + ' ' + \
                                str(k + 1)
                        return
        self.answer = '-1'

    def printAnswer(self):
        print(self.answer)

task = Task()
task.solve()
task.printAnswer()
