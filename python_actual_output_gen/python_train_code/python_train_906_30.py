k,s=map(int,input().split())
count=0
for i in range(0,k):
  for j in range(0,k):
    if 0<=(s-i+j)<=k:
      count+=1
print(count)