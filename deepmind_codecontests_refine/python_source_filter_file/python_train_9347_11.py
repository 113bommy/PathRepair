n=int(input())
a=list(map(int,input().split()))
s=sum(a)
cn=0
buf=s
for i in range(n):
  cn+=a[i]
  buf=min(bug,abs(s-2+cn))
print(buf)
