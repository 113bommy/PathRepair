from sys import stdin, stdout, setrecursionlimit
input = stdin.readline
# setrecursionlimit(int(1e6))
from collections import defaultdict as dd
from collections import Counter, deque
from heapq import *
import math
from math import floor, ceil, sqrt
def geti(): return map(int, input().strip().split())
def getl(): return list(map(int, input().strip().split()))
def getis(): return map(str, input().strip().split())
def getls(): return list(map(str, input().strip().split()))
def gets(): return input().strip()
def geta(): return int(input())
def print_s(s): stdout.write(s+'\n')

class rect:
    def __init__(self, x1, y1, x2, y2):
        self.x1 = x1
        self.x2 = x2
        self.y1 = y1
        self.y2 = y2
    def covered(self, x1, y1):
        return self.x1 <= x1 <= self.x2 and self.y1 <= y1 <= self.y2

    def points(self):
        return [(self.x1, self.y1), (self.x2, self.y1), (self.x1, self.y2), (self.x2, self.y2)]


def solve():
    w = rect(*getl())
    b1 = rect(*getl())
    b2 = rect(*getl())
    corners = 0
    for px, py in w.points():
        if b1.covered(px, py) or b2.covered(px, py):
            corners += 1
    # print(corners)
    if corners != 4:
        print("YES")
    else:
        if (b1.covered(w.x1, w.y1) and b1.covered(w.x2, w.y1)) or (b2.covered(w.x1, w.y1) and b2.covered(w.x2, w.y1)):
            y = w.y2 - w.y1
            y -= max(min(w.y2, b1.y2) - max(w.y1, b1.y1), 0)
            y -= max(min(w.y2, b2.y2) - max(w.y1, b2.y1), 0)
            if y:
                print("YES")
            else:
                print("NO")
        elif (b1.covered(w.x1, w.y1) and b1.covered(w.x1, w.y2)) or (b2.covered(w.x1, w.y1) and b2.covered(w.x1, w.y2)):
                x = w.x2 - w.x1
                x -= max(min(w.x2, b1.x2) - max(w.x1, b1.x1), 0)
                x -= max(min(w.x2, b2.x2) - max(w.x1, b2.x1), 0)
                if x:
                    print("YES")
                else:
                    print("NO")
        else:
            print("NO")


if __name__=='__main__':
    solve()
