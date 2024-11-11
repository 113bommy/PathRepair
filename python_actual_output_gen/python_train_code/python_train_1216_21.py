n=int(input())
l=[list(map(int,input().split())) for i in range(n-1)]

for i in range(n-1):
  t=l[i][1]
  t+=l[i][0]
  for j in range(i+1,n-1):
    if t<l[j][1]:
      t=l[j][1]
    elif t%l[j][2]!=0:
      t+=t%l[j][2]
    t+=l[j][0]

  print(t)
print(0)