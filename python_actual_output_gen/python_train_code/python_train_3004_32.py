M,N=map(int,input().split())
A = list(map(int,input().split()))
b=sum(A)
s=sorted(A)
if s[-M]>=(b/(4*M)):
    print("Yes")
else:
    print("No")