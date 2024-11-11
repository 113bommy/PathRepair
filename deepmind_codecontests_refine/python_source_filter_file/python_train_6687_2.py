import math  
a=[1]*(31) 
for i in range(31):
    a[i]=1<<i 
t=int(input()) 
while t:
    t-=1  
    n,m=map(int,input().strip().split(' ')) 
    k=int(math.log2(n)) 
    prod=1 
    for i in range(k):
        prod=(prod*(a[i]+1))%m  
    r=(n-a[k]+1) 
    prod=(prod*(r+1))%m 
    print(max(prod-1,0))
        
