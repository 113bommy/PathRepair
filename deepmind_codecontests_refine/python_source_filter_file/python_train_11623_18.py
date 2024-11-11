v1,v2,v3,vm=map(int,input().split())

flag=0
l=[]
for i in range(2*v1,v1-1,-1):
  if i>=vm:
      l.append(i)
      break
else:
  flag=1
if not flag:      
  for i in range(2*v2,v2-1,-1):
      if i>=vm and i<l[0]:
          l.append(i)
          break
  else:
      flag=1
if not flag:          
  for i in range(v3,2*v3+1):
    if i>=vm and i<=2*vm and i<l[1]:
      l.append(i)
      break
  else:
      flag=1 
if flag:
  print("-1")
else:
  print(l[0])
  print(l[1])
  print(l[2])