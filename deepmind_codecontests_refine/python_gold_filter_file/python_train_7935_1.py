def f(A):
    n=len(A)
    C=[0]*n
    B=[2,3,5,7,11,13,17,19,23,29,31]
    a=1
    for j in range(11):
        r=0
        for i in range(n):
            if A[i]%B[j]==0 and C[i]==0:
                C[i]=a
                r=1
        if r>0:
            a+=1
    print(a-1)
    return C
t=int(input())
while t>0:
    n=int(input())
    A=list(map(int,input().split()))
    T=f(A)
    for i in T:
        print(i,end=" ")
    t-=1