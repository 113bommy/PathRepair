x,n = map(int,input().split())
p = list(map(int,input().split()))

min=0
dev=200

for i in range(1,102):
  if i in p or abs(x-i)>=dev:
    continue
  dev=abs(x-i)
  min=i
print(min)