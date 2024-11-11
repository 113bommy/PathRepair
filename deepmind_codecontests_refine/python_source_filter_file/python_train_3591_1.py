n,m=map(int,input().split())
if m==1:
    print(2)
elif n-m>=m:
    print(m+1)
else:
    print(m-1)