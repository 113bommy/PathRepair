k=int(input())
l=int(input())
c=0
m='YES'
if l%k==0:
  while l!=k:
      if l<k:
         m='NO'
         break
      
      l=l//k
      c+=1
  if m=='YES':
      print('YES')
      print(c)
  else:
      print(m)
  
else:
  print(-1)    
    