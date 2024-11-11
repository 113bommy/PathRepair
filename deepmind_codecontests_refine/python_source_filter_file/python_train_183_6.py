n=int(input())
a=[int(i) for i in input().split()]
b=[int(i) for i in input().split()]
c=[int(i) for i in input().split()]
sat=sum(b)
for i in range(n-1):
  if a[i+1]==a[i]+1:
    sat+=c[i]
print(sat)
