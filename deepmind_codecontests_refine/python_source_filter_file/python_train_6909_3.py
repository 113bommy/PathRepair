n,l=input().split()
n=int(n)
l=int(l)
l=l-1
a=list(map(int,input().split()))
min=float('inf')
for i in range(n-1,-1,-1):
    if(a[i]<min):
        min=a[i]
        pos=i
if(a[l]==min):
    pos=l
if(l>=pos):
    for i in range(0,n):
        a[i]-=min
    for i in range(pos+1,l+1):
        a[i]-=min
    a[pos]=n*min+l-pos
else:
    found=0
    for i in range(l,-1,-1):
        if(a[i]==min):
            pos=i
            found=1
            break
    if(found==1):
        for i in range(0,n):
            a[i]-=min
        for i in range(pos+1,l+1):
            a[i]-=min
        a[pos]=n*min+l-pos
    else:
        for i in range(0,n):
            a[i]-=min
        for i in range(pos+1,n):
            a[i]-=1
        for i in range(0,l+1):
            a[i]-=1
        a[pos]=n*min+n-pos+l
        
    

for i in range(0,n):
    print(a[i],end=' ')
        
    
    
    
    
    
    
        
        

            
    

    
    