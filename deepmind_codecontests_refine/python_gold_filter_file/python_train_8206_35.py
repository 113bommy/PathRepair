n=int(input())
a=list(map(int,input().split()))
s=sum(a)
sa=a[0]
d=abs(s-2*a[n-1])
for i in range(1,n-1):
  sa+=a[i]
  d=min(abs(s-sa-sa),d)
print(d)
