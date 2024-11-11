n=int(input())
l=[int(i) for i in input().split()]
i=1 
maxi=1
c= 0 
while i<n: 
    while i<n and l[i]<=l[i-1]*2:
        i+=1 
        c+=1 
    maxi=max(maxi,c+1 )
    i+=1 
    c=0 
print(maxi)