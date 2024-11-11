t=int(input())
for _ in range(t):
    x=int(input())
    a=[]
    for i in range(1,10):
        sum=0
        for j in range(0,4):
            sum+=(10**j*i)
            a.append(sum)
            
        
       
    sum=0
    i=0
    j=1
    while(True):
        
        sum+=j
        
        j+=1
        if(j==5):
            j=1
        
        if(a[i]==x):
            break
        i=i+1
        
        
    print(sum)