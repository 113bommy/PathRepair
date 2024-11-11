import sys

input = sys.stdin.readline


def S(): return input()
def I(): return int(S())
def M(): return map(int, S().split())
def L(): return list(M())


t = int(input())
for p in range(t):
    n = I()
    if n == 1:
        print(1, 0)
    elif n == 2:
        print(1, 1)
    else:
        a = n//3
        b = n % 3
        if b == 0:
            print(a, a)
        elif b == 1:
            print(a+1, a)
        else:
            print(a, a+1)
