def examA():
    N = I()
    A = LI()
    ans = "YES"
    cur = 0
    for a in A:
        if a%2==1:
            cur +=1
    if cur%2==1:
        ans = "NO"
    print(ans)
    return

def examB():
    N = I()
    A = LI()
    ans = "YES"
    sumA = sum(A)
    oneA = (1+N)*N//2
    if sumA%oneA!=0:
        ans = "NO"
    ope = sumA//oneA
    #各Aについて何回始点としたか二分探索
    cur = 0
    for i in range(N):
        now = ope - (A[i]-A[i-1])
        if now%N!=0 or now<0:
#            print(now,i)
            ans = "NO"
            break
        cur += now//N
    if cur!=ope:
        ans = "NO"
    print(ans)
    return

import sys,copy,bisect,itertools,heapq,math
from heapq import heappop,heappush,heapify
from collections import Counter,defaultdict,deque
def I(): return int(sys.stdin.readline())
def LI(): return list(map(int,sys.stdin.readline().split()))
def LSI(): return list(map(str,sys.stdin.readline().split()))
def LS(): return sys.stdin.readline().split()
def SI(): return sys.stdin.readline().strip()
global mod,inf
mod = 10**9 + 7
inf = 10**18

if __name__ == '__main__':
    examB()
