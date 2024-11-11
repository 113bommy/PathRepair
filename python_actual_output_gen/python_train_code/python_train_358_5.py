n,k,*a=map(int,open(0).read().split())
d=[1]*n
for i in range(n):d[i]=max(d[j]for j in range(max(0,i-99),i)if abs(a[i]-a[j])<=k)+1
print(max(d))