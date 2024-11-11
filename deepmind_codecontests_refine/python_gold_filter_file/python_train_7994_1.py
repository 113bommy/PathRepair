l=int(input())
a=[]
for i in range(l):
  m,n=(int(i) for i in input().split())
  a.append([n,m])
a.sort()
r="Yes"
s=0
for i in range(l):
  s=s+a[i][1]
  if s>a[i][0]:
    r="No"
    break
print(r)