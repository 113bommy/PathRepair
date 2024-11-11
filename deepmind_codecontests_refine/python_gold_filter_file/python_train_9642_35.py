t=int(input())
n=input()
v,c=0,0
for i in range(0,len(n)-1):
    if(n[i]=='F' and  n[i]!=n[i+1]):
        v+=1
    if(n[i]=='S' and n[i]!=n[i+1]):
        c+=1
if(c>v):
    print("YES")
else:
    print("NO")

    
        
    
    
    