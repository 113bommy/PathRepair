import sys
def input(): return sys.stdin.readline().strip()
N=int(input())
A=[int(input()) for i in range(N-1)]
c=[[] for i in range(N)]
for i,a in enumerate(A):
    c[a-1].append(i+1)
import sys
sys.setrecursionlimit(10**5)
def f(i):
    if len(c[i])==0:
        return 0
    return max([e+i+1 for i,e in enumerate(sorted([f(j) for j in c[i]],reverse=True))])
print(f(0))