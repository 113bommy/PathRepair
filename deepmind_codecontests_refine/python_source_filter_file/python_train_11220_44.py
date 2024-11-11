N=int(input())
l=list(map(int,input().split()))
a=1
l.sort()
print(l)
for i in range(N):
  a=a*l[i]
  if a>10**18:
    print(-1)
    break
if a<=10**18:
  print(a)
