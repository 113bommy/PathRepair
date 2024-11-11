
from collections import *
al=defaultdict(int)
n,u,k=map(int,input().split())
z=list(map(int,input().split()))
z.sort()

m=z.copy()
if(k==1):
    print(len(z))
    exit()

al=defaultdict(int)
total=0
point=z[0]+1
for i in range(len(z)):
    if(point>=len(z)):
        break;
    if(i==0):
        point=m[k-1]
        count=0
        for j in range(k-1,len(z)):
            if(m[j]-z[i]+1>u):
                break;
            else:
                count+=1
                al[j]=1
                
        total+=count
        point=j
        gap=k
        
        
        
    else:
      
        if(al[i]==0):
            gap-=1            
            while(gap<k):
                if(al[point]==0):
                    point+=1
                    gap+=1
                else:
                    point+=1
           
            count=0
           
            for j in range(point,len(z)):
             
                if(z[j]-z[i]+1>u):
                    break;
                else:
                    count+=1
                
                    al[j]=1
            total+=count
            point=j
            gap=k
            
        else:
            continue;
            
            
       
        
   
print(total)
                
            
        
                
    
