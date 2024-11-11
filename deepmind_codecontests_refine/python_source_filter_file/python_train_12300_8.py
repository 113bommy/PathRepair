from bisect import bisect_left
n,m,ta,tb,k=map(int,input().split())
z=list(map(int,input().split()))
r=list(map(int,input().split()))
for i in range(len(z)):
    z[i]+=ta
if(k>=min(m,n)):
    print(-1)
    
inde=bisect_left(r,z[0])
if(inde+k>=m):
    print(-1)
    exit()
mini=r[inde+k]
flag=0
count=1

while(count<=k):
    inde=bisect_left(r,z[count])
    
    if(inde+k-count>=m):
        print(-1)
        exit()
    else:
        mini=max(mini,r[inde+k-count])
        
    count+=1
    
    
print(mini+tb) 
    
