i=input
for _ in[0]*int(i()):
 X,z=i(),[]
 for y in i():
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
