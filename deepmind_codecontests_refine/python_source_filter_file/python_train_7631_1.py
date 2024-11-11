import sys
import io, os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

mod=998244353

def ans(A):
    LEN=len(A)
    ANS=0
    
    for i in range(1<<LEN):
        X=[0]*LEN
        for j in range(LEN):
            if i & (1<<j) != 0:
                X[j]=1

        C=[]
        P=[]
        SC=0
        SP=0
        for i in range(LEN):
            if X[i]==1:
                C.append(i)
                SC+=A[i]
            else:
                P.append(i)
                SP+=A[i]

        if SC>=SP:
            continue

        flag=1
        for i in range(2,len(C)):
            if C[i-1]-C[i-2]>C[i]-C[i-1]:
                flag=0
                break

        for i in range(2,len(P)):
            if P[i-1]-P[i-2]<P[i]-P[i-1]:
                flag=0
                break

        if flag==0:
            continue
        else:
            ANS+=1
    return ANS%mod
        
            
ALIST=[]
t=int(input())
for tests in range(t):
    n=int(input())
    A=list(map(int,input().split()))

    S=[0]*(n+1)
    S2=[0]*(n+1)
    for i in range(n):
        S[i+1]=A[i]+S[i]
        S2[i+1]=A[i]+S2[i-1]
        
    MAX=(S[-1]-1)//2

    #print(S)

    if n<=5:
        ALIST.append(ans(A))
        continue

    ANS=1 # all :P
    
    # right-most
    SUMR=A[-1]

    ind=n-2

    while SUMR<=MAX:
        ANS+=1
        SUMR+=A[ind]
        ind-=1

    #print(ANS)

    # left-most, even, not use last
    indl=0
    if (n-1)%2==0:
        indr=n-3
    else:
        indr=n-2

    while indl<=indr:
        while indl<=indr and S2[indr+1]+S[indl+1]-S2[indl+1]>MAX:
            indr-=2
        #print(indl,indr)
        if indl<=indr:
            ANS+=(indr-indl)//2+1
        indl+=2

    #print(ANS)

    # left-most, odd, not use last
    indl=1
    if (n-1)%2==0:
        indr=n-2
    else:
        indr=n-3

    while indl<=indr:
        while indl<=indr and S2[indr+1]+S[indl+1]-S2[indl+1]>MAX:
            indr-=2
        #print(indl,indr)
        if indl<=indr:
            ANS+=(indr-indl)//2+1
        indl+=2

    #print(ANS)

    # left-most, even, use last
    indl=0
    if (n-1)%2==0:
        indr=n-3
    else:
        indr=n-2

    while indl<=indr:
        while indl<=indr and S2[indr+1]+S[indl+1]-S2[indl+1]+A[-1]>MAX:
            indr-=2
        #print(indl,indr)
        if indl<=indr:
            ANS+=(indr-indl)//2+1
        indl+=2
    #print(ANS)

    # left-most, odd, use last
    indl=1
    if (n-1)%2==0:
        indr=n-4
    else:
        indr=n-3

    while indl<=indr:
        while indl<=indr and S2[indr+1]+S[indl+1]-S2[indl+1]+A[-1]>MAX:
            indr-=2
        #print("!",indl,indr)
        if indl<=indr:
            ANS+=(indr-indl)//2+1
        indl+=2

    #print(ANS)

    # PCCCCC, left-most, even, not use last
    indl=2
    if (n-1)%2==0:
        indr=n-3
    else:
        indr=n-2

    while indl<=indr:
        while indl<=indr and S2[indr+1]+S[indl+1]-S2[indl+1]-A[0]>MAX:
            indr-=2
        #print(indl,indr)
        if indl<=indr:
            ANS+=(indr-indl)//2+1
        indl+=2

    #print(ANS)

    # PCCCCC, left-most, odd, not use last
    indl=1
    if (n-1)%2==0:
        indr=n-2
    else:
        indr=n-3

    while indl<=indr:
        while indl<=indr and S2[indr+1]+S[indl+1]-S2[indl+1]-A[0]>MAX:
            indr-=2
        #print(indl,indr)
        if indl<=indr:
            ANS+=(indr-indl)//2+1
        indl+=2

    #print(ANS)

    # PCCCCC, left-most, even, use last
    SUML=A[0]
    indl=2
    if (n-1)%2==0:
        indr=n-3
    else:
        indr=n-2

    while indl<=indr:
        while indl<=indr and S2[indr+1]+S[indl+1]-S2[indl+1]+A[-1]-A[0]>MAX:
            indr-=2

        #print(indl,indr)
        if indl<=indr:
            ANS+=(indr-indl)//2+1
        indl+=2
    #print(ANS)

    # PCCCCC, left-most, odd, use last
    SUML=A[0]
    indl=1
    if (n-1)%2==0:
        indr=n-4
    else:
        indr=n-3

    while indl<=indr:
        while indl<=indr and S2[indr+1]+S[indl+1]-S2[indl+1]+A[-1]-A[0]>MAX:
            indr-=2
        #print(indl,indr)
        if indl<=indr:
            ANS+=(indr-indl)//2+1
        indl+=2

    ALIST.append(ANS%mod)
sys.stdout.write("\n".join(map(str,ALIST)))

    

    

    
