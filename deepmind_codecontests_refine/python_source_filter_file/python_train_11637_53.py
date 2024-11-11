import sys
input = sys.stdin.readline
N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
RB = B[::-1]

start = v = -1
seq = 0
for i,(a,b) in enumerate(zip(A,RB)):
    if a==b:
        v = a
        seq += 1
        if start == -1:
            start = i

if v == -1:
    print('Yes')
    print(*RB)
    exit()

if A.count(v) + B.count(v) > N:
    print('No')
    exit()

from bisect import bisect_left,bisect
al = bisect_left(A,v)
bl = bisect_left(B,v)
br = bisect(B,v)
rbl = N - br

m = min(seq,start,al,bl)
RB[:m],RB[start:start+m] = RB[start:start+m],RB[:m]
seq -= m
start += m
if seq:
    RB[start:start+seq],RB[-seq:] = RB[-seq:],RB[start:start+seq]

assert all(a!=b for a,b in zip(A,RB))
print('Yes')
print(*RB)