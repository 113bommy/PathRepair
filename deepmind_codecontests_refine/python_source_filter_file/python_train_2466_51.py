def do():
    n = int(input())
    dat = list(map(int, input().split()))
    dat.sort()
    if n==1:
        print(n)
        return
    if n==2:
        print(dat[0])
        return
    if n&1 == 1:
        print(dat[n//2])
        return
    print(dat[n//2 - 1])
do()

def resolve():
    #input = sys.stdin.readline
    from pprint import pprint
    #import sys
    #sys.setrecursionlimit(100000)


    q = int(input())
    for _ in range(q):
        s = input()
        n = int(input())
        n, k = map(int, input().split())
        dat = list(map(int, input().split()))


    dat = [1, 2, 3]
    print(" ".join(list(map(str, res))))

    pass
    import math
    math.ceil(1.2)
    math.floor(1.2)
    round(1.2, 3)

