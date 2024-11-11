n,m=map(int,input().split())
if m==0:
    print("1")
else:
    print(min(m,n-m))