n, p, l ,r=map(int,input().split())
x=(l+r)//2
count=0
if l<=p<=r:
   if l!=1 and r!=n:
      if p<x:
         count+=(p-l)
             
      else:
         count+=(r-p)
      
      count+=(r-l+2)

   elif l==1 and r!=n:
      count+=(r-p+1)
   
   elif l!=1 and r==n:
      count+=(p-l+1)            
         
   print(count)

else:
    if p>r:
      x=p-r+1
      if l!=1:
        y=r-l+1
        count+=(x+y)
      
      else:
        count+=x
    
    elif p<l:
      x=l-p+1
      if r!=n:
        y=l-r+1
        count+=(x+y)
       
      else:
        count+=x
    
    print(count)      
      
               
   
         
   
       


