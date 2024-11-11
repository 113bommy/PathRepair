def binary( x ):
   z = []
   if x==0:
       z.append(0)
       return z
  
   while x!=0:
       z.append(x%2)
       x = int(x/2)
   return z
 
a = []
i = 0
check = 0
while check<=10000:
    temp = binary(i)
    j=0
    s=0
    for k in temp:
        s+= k*(3**j)
        j+=1
    check = s
    a.append(check)
    i+=1
    
    
q = int(input())
 
while q != 0:
    n = int(input())
    for i in a:
        if i>=n:
            print(i)
            break
    q-=1
    