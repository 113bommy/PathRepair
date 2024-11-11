n,m=map(int, input().split())
f=1
c=0


for i in range (1,n+1):
    for j in range (1, m+1):
       if(i%2!=0):
           print("#", end=""),
       else:
           if(j==1 and f==0):
               print("#", end=""),
              
           elif(j==m and f==1):
               print("#", end=""),
               
           else:
               print(".", end=""),

    if(f==0 and i%2==0):
        f=1
    elif(f==1 and i%2==0):
        f=0  
    print("\n")
    
        
   

