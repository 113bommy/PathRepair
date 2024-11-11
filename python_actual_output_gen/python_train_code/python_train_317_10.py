N=int(input())
H=map(int,input().split())
m=0
c=0
for h in H:
  c += 1 if h>m else 0
  m=max(m,h)
print(c)