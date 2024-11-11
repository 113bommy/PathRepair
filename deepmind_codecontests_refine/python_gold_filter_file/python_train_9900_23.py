n,k=map(int,input().split())

if k%2==1:
    if k//2+1>n:
        ANS=0
    else:
        ANS=min(n-k//2,k//2)

else:
    if k//2+1>n:
        ANS=0
    else:
        ANS=min(k//2-1,n-k//2)

print(ANS)
    
