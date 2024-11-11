import sys
input = sys.stdin.readline


def solveeven(border):
    l = -1
    r = 10**5
    while r-l > 1:
        m = (r+l)//2
        num = m*2 if m%2 == 0 else m*2+1
        if num*(num+1)//2 >= border:
            r = m
        else:
            l = m
    return r*2 if r%2==0 else r*2+1

def solveodd(border):
    l = -1
    r = 10**5
    while r-l > 1:
        m = (r+l)//2
        num = m*2 if m%2 == 1 else m*2+1
        if num*(num+1)//2 >= border:
            r = m
        else:
            l = m
    return r*2 if r%2==1 else r*2+1



Q = int(input())
Query = [list(map(int, input().split())) for _ in range(Q)]
for a, b in Query:
    diff = abs(a-b)
    if diff%2 == 0:
        print(solveeven(diff))
    else:
        print(solveodd(diff))