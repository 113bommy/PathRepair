def examA():
    Alpha = [chr(i) for i in range(97, 97+26)]
    S = SI(); N = len(S)
    ans = -1
    for i in range(N):
        for s in Alpha:
            cur = [s for s in S]
            for l in range(i):
                for k in range(N-1):
                    if cur[k+1]==s:
                        cur[k]=s
 #           print(cur)
            if len(Counter(cur[:N-i]))==1:
                ans = i
                break
        if ans>=0:
            break
    print(ans)
    return

def examB():
    N = I()
    A = LI()
    d = defaultdict(int)
    for a in A:
        d[a] +=1
    l = min(d); r = max(d)
    ans = "Yes"
    if l>=N:
        ans = "No"
    if r-l>1:
        ans = "No"
    if d[l]>l:
        ans = "No"
    if (r-d[l])*2+d[l]>N:
        ans = "No"
    if r==l and (N-l==1 or N//2>=l):
        ans = "Yes"
    print(ans)
    return

def examC():
    H, W, h, w = LI()
    judge = (H%h)+(W%w)
    if judge==0:
        print("No")
        return
    print("Yes")
    now = 4*(h+w)
    neg = -(h*w-1)*now-1
    A = [[now]*W for _ in range(H)]
    for i in range(1,1+H//h):
        for j in range(1,1+W//w):
            A[i*h-1][j*w-1] = neg
    for v in A:
        print(" ".join(map(str,v)))
    return

import sys,copy,bisect,itertools,heapq,math
from heapq import heappop,heappush,heapify
from collections import Counter,defaultdict,deque
def I(): return int(sys.stdin.readline())
def LI(): return list(map(int,sys.stdin.readline().split()))
def LSI(): return list(map(str,sys.stdin.readline().split()))
def LS(): return sys.stdin.readline().split()
def SI(): return sys.stdin.readline().strip()
mod = 10**9 + 7
inf = float('inf')

if __name__ == '__main__':
    examC()
