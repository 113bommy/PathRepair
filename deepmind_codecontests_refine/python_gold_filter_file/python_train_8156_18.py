x,y,a,b = map(int,input().split(' '))
count=0;flag=1
comb=[]
if a<b:
  if x>=b:
    a=b
  else:
    print(0)
    flag=0
if flag is not 0:
  for i in range(a,x+1):
    for j in range(b,min(i+1,y+1)):
      if i is j:
        continue
      else:
        comb.append([i,j])
        count+=1
  print(count)
  if count>0:
    for i in comb:
      print(*i)