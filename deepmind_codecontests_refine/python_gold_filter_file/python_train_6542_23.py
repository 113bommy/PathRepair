n,p=map(int, input().split())
A=[int(i)%2 for i in input().split()]
t=sum(A)

if t==0:
    if p==1:
        print(0)
    else:
        print(2**n)
else:
    print(2**(n-1))
