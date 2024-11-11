import heapq
import sys
def I(): return int(sys.stdin.readline())
def LI(): return list(map(int,sys.stdin.readline().split()))
mod = 10**9 + 7
inf = float('inf')

S = str(input())
N = len(S)
ans = int(0)

k = N

for i in range(N-1):
    if S[i]!=S[i+1]:
        k = max(i+1,N-1-i)
ans = k
print(ans)