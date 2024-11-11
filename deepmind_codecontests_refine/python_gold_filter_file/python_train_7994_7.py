n=int(input())
a=[list(map(int,input().split())) for _ in range(n)]
a.sort(key=lambda x: x[1])
t=0
for i in range(n):
  t+=a[i][0]
  if t>a[i][1]:
    print("No")
    break
  elif i==n-1:
    print("Yes")
