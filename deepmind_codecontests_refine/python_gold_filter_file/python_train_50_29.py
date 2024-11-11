l=list(map(int,input().split()))
butt,bulbs=l[0],l[1]
i=1
x=[]
while(i<=butt):
  l=list(map(int,input().split()))
  x=x+l[1:] 
  i+=1
d=list(range(1,bulbs+1))  
q=0
f=True
while(q<bulbs and f==True):
  tmp=d[q]
  i=0
  f=False
  while(i<len(x) and f==False):
    if(x[i]==tmp):
      f=True
    i+=1
  q+=1  

if(f==True):
  print('YES')
else:
  print('NO')
  

