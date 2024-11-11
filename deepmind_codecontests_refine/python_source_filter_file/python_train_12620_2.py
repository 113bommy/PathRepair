N=int(input())
L=list(map(int,input().split()))
MAX=0
ANS=[]
for i in range(N):
    B=L[:]
    for j in range(i-1,-1,-1):
        L[j]=min(L[j],L[j+1])
    for j in range(i+1,N):
        L[j]=min(L[j],L[j-1])
    S=sum(B)
    if S>MAX:
        MAX=S
        ANS=B[:]
print(*ANS)