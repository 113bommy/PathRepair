n=int(input())
a=[int(input()) for _ in range(n)]
p=a[::]
m=max(a)
a.delete(m)
m2=max(a)
for i in p:
  if i==m:
    print(m2)
  else:
    print(m)