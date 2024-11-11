n,m=map(int,input().split())
a=list(map(int,input().split()))
a=sorted(a)[::-1]
s=sum(a)
print("Yes" if a[m-1]>=s/4/m else "No")