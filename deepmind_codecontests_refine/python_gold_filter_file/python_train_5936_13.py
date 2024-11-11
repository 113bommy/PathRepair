for _ in[0]*int(input()):
 X,z=input(),[]
 for y in input():
  s=i=0
  for k in z:
   t=X.find(y,s)+1
   if t<1:break
   if t<k:z[i]=t
   s=k;i+=1
  else:
   t=X.find(y,s)+1
   if t:z+=[t]
 print(len(z))
