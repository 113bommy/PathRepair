import sys
def MI(): return map(int,sys.stdin.readline().rstrip().split())

N,C = MI()
A = [[0]*(10**5+2) for i in range(C+1)]
for i in range(N):
    s,t,c = MI()
    A[c][s] += 1
    A[c][t+1] -= 1

from itertools import accumulate

for i in range(1,C+1):
    A[i] = list(accumulate(A[i]))

# A[i][j] が正 ⇔ チャンネル i が時刻 j に録画機が必要

ans = 0
for j in range(10**5+2):
    ans = max(ans,sum(A[i][j] > 0 for i in range(1,C+1)))

print(ans)
