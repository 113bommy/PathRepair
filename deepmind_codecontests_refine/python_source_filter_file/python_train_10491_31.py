# coding: utf-8
N,K=map(int,input().split())
A=list(map(int,input().split()))
MOD=10**9+7

ans=1

if K==N:
    for i in range(N):
        ans*=A[i]
        if ans>0:
            ans=ans%MOD
elif max(A)<0 and K%2==1:
    A.sort(reverse=True)
    for i in range(K):
        ans*=A[i]
        if ans>0:
            ans=ans%MOD
else:
    Ap=[]
    Am=[]
    
    for i in range(N):
        if A[i]>0:
            Ap.append(A[i])
        else:
            Am.append(A[i])
        

    Ap.sort(reverse=True)
    Am.sort()
    
    if K%2==1 and Ap:
        ans*=Ap.pop(0)
    
    
    P=[]
    
    for i in range(len(Ap)//2):
        P.append(Ap[i*2]*Ap[i*2+1])
    
    for i in range(len(Am)//2):
        P.append(Am[i*2]*Am[i*2+1])
    
    P.sort(reverse=True)
    
    for i in range(K//2):
        ans*=P[i]
        ans=ans%MOD

print(ans%MOD)