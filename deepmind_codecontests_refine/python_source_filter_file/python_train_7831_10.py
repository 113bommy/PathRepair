t=int(input())


for i in range(t):
   newstring=""
   x=set()
   k=input()
   b=len(k)
   for j in k:
     x.add(j)
      
   for i in x:
       newstring=newstring+i
   
     
   print(newstring*2)
     