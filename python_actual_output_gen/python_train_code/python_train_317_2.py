a=int(input())
b=list(map(int,input().split()))
c=0
d=0
for i in range(a):
  if c<b[i]:
    c=b[i]
    d=d+1
print(d)