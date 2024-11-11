import math,sys,bisect,heapq
from collections import defaultdict,Counter,deque
from itertools import groupby,accumulate
#sys.setrecursionlimit(1000000)
input = iter(sys.stdin.buffer.read().decode().splitlines()).__next__
ilele = lambda: map(int,input().split())
alele = lambda: list(map(int, input().split()))
#def list2d(a, b, c): return [[c] * b for i in range(a)]
#def list3d(a, b, c, d): return [[[d] * c for j in range(b)] for i in range(a)]
#MOD = 1000000000 + 7
def Y(c):  print(["NO","YES"][c])
def y(c):  print(["no","yes"][c])
def Yy(c):  print(["No","Yes"][c])

for _ in range(int(input())):
    s = input()
    C = Counter(s)
    N = int(input())
    A = alele()
    S = sorted(s)
    #print(S)
    Ans = [""]*N
    while True:
        D = []
        for i in range(N):
            if A[i]== 0:
                D.append(i)
        l = len(D)
        if l == 0:
            break
        while len(S) > 0 and C[S[-1]] < l:
            S.pop()
        #print(S,l,D)
        if len(S):
            for j in D:
                for i in range(N):
                    if i not in D:
                        A[i] -= abs(i - j)
                    else:
                        A[i] = -1
                y = S.pop()
                C[y] -=1
                Ans[j] = y
        else:
            break
        #print(A)
    print("".join(Ans))
        
            
        
                