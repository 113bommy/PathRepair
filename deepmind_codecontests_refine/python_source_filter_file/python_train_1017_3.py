n,k,s=map(int,input().split())
a=[s]*k
if s!=10**9:
    a+=[10**9]*(n-k)
    print(a)
else:
    b=[10**9]*k+[1]*(n-k)
    print(b)