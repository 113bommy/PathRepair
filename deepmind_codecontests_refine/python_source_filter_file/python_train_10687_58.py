n,k=map(int,input().split())
while k>0:
    temp=n
    d=temp%10
    if d!=0:
        n=n-1
    else:
        n=n/10
    k=k-1
print(n)