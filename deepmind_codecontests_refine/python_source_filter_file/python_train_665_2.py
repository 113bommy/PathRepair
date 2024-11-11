ncards=int(input())
numbers=input()
numbers=numbers+" "
cost=""
ar=[0]*ncards
c=0
for i in range(len(numbers)):
  if numbers[i]!=" ":
    cost=cost+numbers[i]
  else:
    ar[c]=int(cost)  
    c=c+1
    cost= " "
c1=0
c2=0
e=0
f=0
while e<ncards-1-f:
  if ar[e]>ar[ncards-1-f]:
    c1=c1+ar[e]
    e=e+1
    if ar[e+1]>ar[ncards-1-f]:
      c2=c2+ar[e]
      e=e+1
    else :
      c2=c2+ ar[ncards-1-f] 
      f=f+1  
  else:
     c1=c1+ar[ncards-1-f]
     f=f+1
     if ar[e]>ar[ncards-1-f]:
      c2=c2+ar[e]
      e=e+1
     else :
      c2=c2+ ar[ncards-1-f]
      f=f+1
if (ncards%2)!=0 :
  c1=c1+ar[e]  
print(c1,c2)



