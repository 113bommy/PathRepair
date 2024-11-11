import copy
import math
from sys import stdin


def A():
    t = int(stdin.readline())
    while t:
        t -= 1
        cnt  = 0
        k = int(stdin.readline())
        i = 0
        while True:
            if i % 3 == 0 or i % 10 == 3:
                i+= 1
                continue
            cnt += 1
            if cnt == k:
                break
            i += 1
        print(i)
def B():
    t = int(stdin.readline())
    while t:
        t -= 1
        a, b ,c  = [int(x) for x in stdin.readline().split()]
        k = abs(b - a)
        k1 = c + k

        if  k * 2 < max(a,b,c):
            print(-1)
        elif k1 > k * 2:
            k1 = c - k
            if k1 >= 0:
                print(k1)
            else:
                print(-1)
        else:
            print(k1)

def C():
    t = int(stdin.readline())
    while t:
        t -= 1
        a = [int(x) for x in stdin.readline().split()]
B()