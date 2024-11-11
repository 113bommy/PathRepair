import sys,math
input=sys.stdin.readline

T=int(input())
for _ in range(T):
    N,K=map(int,input().split())
    S=list(input())
    S.sort()
    D=1
    flag=0
    v1=1
    C=[S[1]]
    for i in range(2,N+1):
        if (S[i]!=S[i-1]):
            D=D+1
            C.append(S[i])
    
    B=[0 for i in range(D)]
    j=0
    for i in range(1,N+1):
        if(S[i]==C[j]):
            B[j]=B[j]+1
        else:
            j=j+1
            B[j]=B[j]+1
            
    if (B[0]<K):
        K1=K
        for i in range(D):
            if (K1-B[i]<=0):
                print(C[i])
                break
            K1=K1-B[i]
    else:
        if (D==1):
            print(C[0]*math.ceil(B[0]/K))
        elif(D==2 and B[0]==K):
            print(C[0]+C[1]*math.ceil(B[1]/K))
            
        else:
            #print(C,B)
            s=(C[0]*(B[0]-K+1))
            for i in range(1,D):
                s=s+C[i]*B[i]
            print(s)
        
            
        
        
