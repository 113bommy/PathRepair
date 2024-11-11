a,b=map(int,input().split())
res=0
for i in range(a,b+1):
  i=str(i)
  if i[0]==i[4] and i[1]==i[3]:
    res+=1
print(res)