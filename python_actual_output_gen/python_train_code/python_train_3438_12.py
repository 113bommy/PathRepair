x=int(input())
l=[]
for i in range(2,x+1):
  t=i*i
  while t <=x:
    l.append(t)
    t*=i
print(max(l))