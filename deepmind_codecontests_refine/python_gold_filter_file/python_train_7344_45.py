n,b,d=map(int,input().split())
l = list(map(int,input().split()))
s=0
c=0
prev = 0
for i in range(n):
  if l[i]<=b:
    s+=l[i]
  if s>d:
    c+=1
    s=0

print(c)