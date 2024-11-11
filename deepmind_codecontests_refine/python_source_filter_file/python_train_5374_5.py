from collections import Counter
n = int(input())
a = list(map(int,input().split()))
c = Counter(a)
b=dict()
for i in c.keys():
  b[i]=0
d = list(sorted((Counter(range(1,n+1))-c).keys()))
r = n-len(c)
j=0
print(r)
for i in range(n):
  if j==r:
    break
  if c[a[i]]>1:
    if d[0]<a[i]:
      c[a[i]]-=1
      a[i]=d[j]
      j+=1
    else:
      if b[a[i]]!=0:
        c[a[i]]-=1
        a[i]=d[j]
        j+=1
      else:
        b[a[i]]+=1
print(*a)