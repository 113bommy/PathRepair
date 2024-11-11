import sys

#this solves only a specific orientation
#is fine because we consider all orientations
import itertools


def can(h1, w1, h2, w2, h3, w3, c1, c2, c3, tot):
    #height = h1
    if tot % h1 == 0 or tot % h1 != h1:
        # side by side or on top of each other are the two options
        # side by side
        if h1 == h2 == h3:
            print(h1)
            for r in range(h1):
                temp = ""
                for c in range(w1 + w2 + w3):
                    if c < w1: temp += c1
                    elif c < w1 + w2: temp += c2
                    else: temp += c3
                print(temp)
            return True
        if h2 + h3 == h1 and w2 == w3:
            print(h1)
            for r in range(h1):
                temp = ""
                for c in range(w1 + w2):
                    if c < w1: temp += c1
                    else:
                        if r < h2: temp += c2
                        else: temp += c3
                print(temp)
            return True
    return False


def solve(perm):
    x1, y1 = perm[0][0][0],  perm[0][0][1]
    x2, y2 = perm[1][0][0],  perm[1][0][1]
    x3, y3 = perm[2][0][0],  perm[2][0][1]
    c1 = perm[0][1]
    c2 = perm[1][1]
    c3 = perm[2][1]
    tot = x1 * y1 + x2 * y2 + x3 * y3
    for sw1 in range(2):
        for sw2 in range(2):
            for sw3 in range(2):
                h1, w1, h2, w2, h3, w3 = x1, y1, x2, y2, x3, y3
                if sw1 == 1: h1, w1 = w1, h1
                if sw2 == 1: h2, w2 = w2, h2
                if sw3 == 1: h3, w3 = w3, h3
                if can(h1, w1, h2, w2, h3, w3, c1, c2, c3, tot):
                    return True

def supersolve():
    x1, y1, x2, y2, x3, y3, = rv()
    a = [([x1, y1], 'A'), ([x2, y2], 'B'), ([x3, y3], 'C')]
    for perm in itertools.permutations(a):
        if solve(perm): return
    print(-1)


def prt(l): return print(' '.join(map(str, l)))
def rs(): return map(str, input().split())
def rv(): return map(int, input().split())
def rl(n): return [list(map(int, input().split())) for _ in range(n)]  
if sys.hexversion == 50594544 : sys.stdin = open("test.txt")
supersolve()