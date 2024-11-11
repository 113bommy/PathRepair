import sys, os
from collections import defaultdict
input = sys.stdin.readline
read = lambda: list(map(int, input().strip().split()))


def f(p, t):
    return(max((3*p)//10, 9 - (p//250)*t))

def main():
    a,b,c,d = read()
    x, y = f(a, c), f(b, d)
    if x > y:print("Misha")
    elif x < y:print("Vasya")
    else:print("Tie")

if __name__ == "__main__":
    main()
