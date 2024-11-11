# coding: utf-8
import sys
sys.setrecursionlimit(int(1e7))
R = lambda : map(int, input().split())

def main():
    (n,), l = R(), list(R())
    if any(x%2==0 for x in l) and any(x%2==1 for x in l):
        l.sort()
    print(' '.join(map(str, l)))
    return

while 1:
    try: main()
    except EOFError: break