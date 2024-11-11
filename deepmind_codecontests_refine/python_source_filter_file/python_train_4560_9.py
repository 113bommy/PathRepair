import sys
input = sys.stdin.readline

N,K=map(int,input().split())
A=list(map(int,input().split()))
F=list(map(int,input().split()))

A.sort()
F.sort(reverse=True)


MIN=0
MAX=max(A)*max(F)

while MIN!=MAX:
    mid=(MIN+MAX)//2
    score=0

    for i in range(N):
        if A[i]*F[i]>mid:
            score+=A[i]-mid//F[i]

    if score<=K:
        MAX=mid
    else:
        MIN=mid+1

print(MIN)
