l,r,d=map(int,input().split())
ct=0
for i in range(l,r+1):
  if i%d==0:
    ct += 1
print(ct)