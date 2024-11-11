import sys
input = sys.stdin.readline

N,K=map(int,input().split())
A=list(map(int,input().split()))

OK=10**9
NG=-1

while OK-NG>1:
    mid=(OK+NG)//2

    ANS=0
    for a in A:
        ANS+=(a-0.01)//mid

    if ANS<=K:
        OK=mid
    else:
        NG=mid
print(OK)
