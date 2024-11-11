n,k=map(int,input().split())
a=list(map(int,input().split()))
c=10**10
for i in range(n-k+1):
    c=min(c,abs(a[i]+a[i+k-1]\
          -min(abs(a[i]),abs(a[i+k-1]))))
print(c)
