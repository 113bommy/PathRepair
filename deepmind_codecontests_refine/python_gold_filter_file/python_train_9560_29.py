a,s=map(int,input().split())
ad=0
for i in range(a,s+1):
  if str(i)==str(i)[::-1]:ad+=1
print(ad)