n=int(input())
l=list(map(int,input().split()))
k=0
if l[0]==0 :
    k=1
for i in range(1,n-1) :
    if l[i]==0 and l[i-1]==0 or l[i]==0 and l[i+1]==0 :
        k=k+1
if l[n-1]==0 :
    k=k+1
print(n-k)
        
    
