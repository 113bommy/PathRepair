n,m=map(int,input().split())
if n==1 and m==1:
    print(1)
elif n==1 or M==1:
    print(n*m-2)
else:
    print((m-2)*(n-2))
