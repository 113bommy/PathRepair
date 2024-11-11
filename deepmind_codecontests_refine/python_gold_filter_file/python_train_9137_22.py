N,P=map(int,input().split())
S=input()
if P==2 or P==5:
    x=0
    for j in range(N):
        if int(S[j])%P==0:
            x+=j+1
    print(x)
else:
    A=[0]*P
    a=0
    b=1
    for i in range(N):
        a=(a+int(S[(N-1-i)])*b)%P
        A[a]+=1
        b=(b*10)%P
    x=A[0]
    for k in range(P):
        x+=int(A[k]*(A[k]-1)/2)
    print(x)
    