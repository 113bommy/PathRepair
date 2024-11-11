import math
n=int(input())
for x in range(0,n):
    mylist=[]
    num=int(input())
    i=1
    while i**2<=n:
        mylist.append(i**2)
        i+=1
        
    j=1
    while j**3<=n:
        if int(math.sqrt(j**3))**2!=j**3:
            mylist.append(j**3)
        j+=1
            
    print(len(mylist))