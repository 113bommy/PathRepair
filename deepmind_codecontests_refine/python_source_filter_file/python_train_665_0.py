n=int(input())
a=list(map(int,input().split()))
s=0;d=0;
for i in range(1,n+1):
    maxi=max(a)
    ind=a.index(maxi)
    a.pop(ind)
    if(i%2!=0):
        s+=maxi
    else:
        d+=maxi
print(s,d)
        
        
    
