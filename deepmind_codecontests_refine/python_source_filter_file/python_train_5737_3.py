
n=int(input())
A=[]
B=[]
if n==1:
    print(0)
else:
    for i in range(n):
        least=list(map(int,input().split()))
        A.append(least[0])
        B.append(least[1])
    minA=max(A)
    maxB=min(B)
    C=A[:]
    D=B[:]
    B.remove(B[A.index(minA)])
    A.remove(minA)
    a=min(B)
    b=max(A)
    C.remove(C[D.index(maxB)])
    D.remove(maxB)
    x=min(C)
    y=max(D)
    ans=max(a-b,y-x)
    if ans>=0:
        print(ans)
    else:
        print(0)