n=int(input())
l=list(map(int,input().split()))
l=sorted(l)
l=l[::-1]
k=0
b=-1

for i in range(n-1) :
    if l[i]==l[i+1] and b==-1 :
        b=l[i]
        l[i+1]=-1
    if l[i]==l[i+1] and b!=1 :
        k+=b*l[i]
        b=-1
        l[i]=-1
    if l[i]==l[i+1]+1 and b==-1:
        b=l[i]-1
        l[i+1]=-1
    if l[i]==l[i+1]+1 and b!=1 :
        k+=b*(l[i]-1)
        b=-1
        l[i]=-1
    
        
print(k)
    
        
    
