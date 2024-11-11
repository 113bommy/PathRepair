def check(x):
  r=x%3
  a=x//3
  if r==0:
    return [a,a]
  elif r==1:
    return [a+1,a]
  else:
    return [a,a+1]
listf=[]
t=int(input())
for x in range(t):
  n=int(input())
  m=''
  a=check(n)
  for y in a:
    m+=str(y)+' '
  listf.append(y)
for g in listf:
  print(g)