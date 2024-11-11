n, m, c=map(int, input().split())
b=list(map(int, input().split()))
ac=0
for _ in range(n):
  ans=c
  a=list(map(int, input().split()))
  for i in range(n):
    ans+=a[i]*b[i]
  if ans>0:
    ac += 1
print(ac)