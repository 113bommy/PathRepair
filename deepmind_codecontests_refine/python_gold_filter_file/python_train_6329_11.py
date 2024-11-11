N,K=map(int,input().split())
A=list(map(int,input().split()))
tmp=10**9+7

cna=0
for i,a in enumerate(A):
    for at in A[i+1:]:    
        if a>at:
            cna+=1

cna2=0
for a in A:
    for at in A:    
        if a>at:
            cna2+=1


kt=(K-1)*(K)//2

print((K*cna+kt*cna2)%tmp)
