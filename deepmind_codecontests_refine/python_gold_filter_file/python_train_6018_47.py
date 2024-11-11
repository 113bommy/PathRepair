P=[1,10,9,12,3,4]
m=10**9+7
def f(A,p,N):
    if p==0:return [1&(i in N) for i in range(13)]
    p%=6
    B=[0]*13
    for n in N:
        for i in range(13):
            c=(i+(n*P[p]))%13
            B[c]=(B[c]+A[i])%m
    return B

S=reversed(input())
A=[0]
for p,s in enumerate(S):
    if s=="?":A=f(A,p,range(10))
    else:A=f(A,p,[int(s)])
print(A[5])