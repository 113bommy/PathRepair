input()
h=list(map(int,input().split()))
m=0
r=True
for i in h:
  r=i>=m-1
  if r:
    break
  m=max(m,i)
print("NYoe s"[r::2])