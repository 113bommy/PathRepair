m,d=input().strip().split(' ')
m,d=[int(m),int(d)]
c=0
for i in range(22,d+1):
  d1=str(d)
  if int(d1[1])>=2 and int(d1[1]*d1[0])<=m:
    c+=1
print c