q=int(input())
for p in range(q):
    n,k=list(int(j) for j in input().split())
    b=input()
    A=list(b)
    i=0
    pos=-1
    while(i<n and k>0):
        if(pos<0 and A[i]=='1'):
            pos=i
        elif(A[i]=='0' and pos>=0):
            jump=i-pos
            if(jump<=k):
                A[i],A[pos]=A[pos],A[i]
                k-=jump
                pos+=1
            else:
                A[i],A[i-k]=A[i-k],A[i]
                k=0
        i+=1
    A="".join(A)
    print(A)
