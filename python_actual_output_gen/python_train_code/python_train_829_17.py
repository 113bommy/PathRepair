n,m,k=map(int,input().split())
a=list(map(int,input().split()))
d=n
for i in range(n):
    if a[i] !=0 and a[i] < k:d=min(d,abs(i-m+1))
print(d*10)