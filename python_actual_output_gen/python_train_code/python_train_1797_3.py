n,d = map(int,input().split())
x = [list(map(int,input().split())) for _ in range(n)]

c=0
for i in range(n-1):
  for j in range(i+1,n):
    c+=(sum((a-b)**2 for a,b in zip(x[i],x[j]))**0.5).is_integer

print(c)