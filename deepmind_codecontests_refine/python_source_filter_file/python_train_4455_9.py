n,k=map(int,input().split())
print(sum(1+i*(n-i+1)for i in range(k,n+2))%(1e9+7))