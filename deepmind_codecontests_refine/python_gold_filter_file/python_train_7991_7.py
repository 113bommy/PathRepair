import sys
input = sys.stdin.readline

N, K = map(int, input().split())
A = list(map(int, input().split()))


l = 0
r = 2*10**9

while r - l > 1:
    m = (l+r)//2
    count = 0
    for a in A:
        count += (a+m-1)//m-1
    if count <= K:
        r = m
    else:
        l = m
    
print(r)