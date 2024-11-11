t=int(input())
for i in range(t):
    n=int(input())
    a=list(map(int,input().split()))[:n]
    a=sorted(a)
    c=0
    s=0
    for i in range(0,n,2):
        if(a[i+1]-a[i]==1):
            c=1
            break
    for i in range(n):
        if(a[i]%2!=0):
            s=s+1
    if((c==1)or(s%2==0)):
        print("YES")
    else:
        print("NO")
            
            
        
    
