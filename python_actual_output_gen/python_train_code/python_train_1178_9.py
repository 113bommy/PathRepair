n,l=map(int,input().split())
a=(l-1)*n+((n+1)*(n))//2
print(a if l-1<=0<=l+n-1 else (a-l if 0<l-1else a-l-n+1))