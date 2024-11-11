n=int(input().strip())
a=[int(e) for e in input().split()]
t1,t2=1,10**6
mini=100000
sigma=0
time=0

if a[-1]-t1<t2-a[-1]:
    print(a[-1]-t1)
elif t2-a[0]<a[0]-t1:
    print(t2-a[0])
else:
    for i in range(0,len(a)-1):
        if a[i]-t1<t2-a[i+1]:
            time=t2-a[i+1]
        else:
            time=a[i]-t1
        if time<mini:
            mini=time
    print(int(mini))
    
    
    
          
    
    
        
        

        
        
