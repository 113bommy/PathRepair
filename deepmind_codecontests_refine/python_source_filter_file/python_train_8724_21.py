n,m=map(int, input().split())
l=range(1,m+1)
for i in range(n):
  b=list(map(int, input().split()))
  b.pop(b[0])
  l=set(l)&set(b)

print(len(l))
    