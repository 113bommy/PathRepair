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

def examC():
    N = I()
    A = LI()
    V = [[]for _ in range(N)]
    for i in range(N-1):
        a, b = LI()
        V[a-1].append(b-1)
        V[b-1].append(a-1)
    s = -1
    for i,v in enumerate(V):
        if len(v)>1:
            s = i
            break
    if s==-1:
        if A[0]==A[1]:
            print("YES")
        else:
            print("NO")
        return
    def dfs(s,p):
        flag = 1
        rep = 0
        maxA = 0
        for v in V[s]:
            if v==p:
                continue
            cur,next = dfs(v,s)
            if maxA<cur:
                maxA = cur
            rep += cur
            flag *= next
        if len(V[s])==1:
            return A[s],flag
        if (rep+1)//2>A[s] or rep<A[s] or maxA>A[s]:
            flag = 0
        #print(s,rep)
        rep -= (rep-A[s])*2
        return rep,flag
    rep,flag = dfs(s,-1)
    if rep!=0:
        flag = 0
    if flag:
        print("YES")
    else:
        print("NO")
    return

from decimal import Decimal as dec
import sys,bisect,itertools,heapq,math,random
from copy import deepcopy
from heapq import heappop,heappush,heapify
from collections import Counter,defaultdict,deque
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
def DI(): return dec(input())
def LDI(): return list(map(dec,sys.stdin.readline().split()))
def I(): return int(input())
def LI(): return list(map(int,sys.stdin.readline().split()))
def LSI(): return list(map(str,sys.stdin.readline().split()))
def LS(): return sys.stdin.readline().split()
def SI(): return sys.stdin.readline().strip()
global mod,mod2,inf,alphabet,_ep
mod = 10**9 + 7
mod2 = 998244353
inf = 1<<60
_ep = 10**(-16)
alphabet = [chr(ord('a') + i) for i in range(26)]

sys.setrecursionlimit(10**7)

if __name__ == '__main__':
    examC()
