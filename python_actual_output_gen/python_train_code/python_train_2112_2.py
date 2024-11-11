import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

import itertools

N = int(readline())
S = list(map(int,read().split()))

answer = 0
for d in range(1,N):
    n = (N-1-d)//d
    if (N-1)%d == 0:
        n = ((N-1)//d+1)//2
    if n <= 1:
        continue
    x = max(itertools.accumulate(x+y for x,y in zip(S[d:d*n:d],S[N-1-d:N-1-d*n:-d])))
    if answer < x:
        answer = x

print(answer)