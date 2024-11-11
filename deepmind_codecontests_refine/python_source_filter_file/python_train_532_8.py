l=[int(x) for x in input().split()]
m=[int(x) for x in input().split()]
n=[int(x) for x in input().split()]
o=[int(x) for x in input().split()]
ans=0
for i in o:
    
    p=m[i-1]
    s=m[i-1]
    ma=-1
    for j in range(l[0]):
        if(n[j]==s):
            if(m[j]>ma):
                ma=m[j]
                
    if(p<ma):
        ans+=1 
print(ans)        
        
    
