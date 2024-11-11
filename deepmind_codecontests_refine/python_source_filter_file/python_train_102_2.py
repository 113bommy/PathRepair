n=int(input())
a=list(map(int,input().split()))
b=c=0
for i in range(n-1):
 m=a.index(min(a[i:]))
 if a[i]>a[m]:
  a[i],a[m]=a[m],a[i];c+=1
print(*a)
print(c)
