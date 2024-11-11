n=int(input())
a=[int(x) for x in input().split()]
m=min(a)
k=m%n
l=a.index(m)
flag=0
for i in range(n):
    a[i]-=m
if k<=l:
    
    p=1
    for i in range(k,l+1):
        a[i]-=p
        p+=1
        if a[i]<=0:
            ans=i
            flag=1
            break
        
        
            
else:
    p=1
    for i in range(k,n):
        
        a[i]-=p
        p+=1
        if a[i]<=0:
            ans=i
            flag=1
            break
    if flag==0:
        for i in range(0,l+1):
            a[i]-=p
            p+=1
            if a[i]<=0:
                ans=i
                flag=1
                break
        
print(ans+1)
        
