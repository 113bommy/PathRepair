a,b,c,d,e,f=map(int,input().split())
l=[]
for i in range(0,(f//(100*a))+1):
  for j in range(0,(f//(100*b))+1):
    if 100*a*i+100*b*j>=f:
      pass
    else:
      l.append(100*a*i+100*b*j)
l1=[]
del l[0]
max1=0
g=0
h=0
for i in l:
  l2=[]
  m=min(f-i,(i//100)*e)
  max2=0#satounoryou
  for j in range(0,(m//c)+1):
    for k in range(0,(m//d)+1):
      if j*c+k*d<=m and j*c+k*d>max2:
        max2=j*c+k*d
  if max1<100*max2/(i+max2):
    g=i
    h=max2
    max1=100*max2/(i+max2)
print(g+h,h)
