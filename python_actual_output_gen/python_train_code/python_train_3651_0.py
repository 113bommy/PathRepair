n,k=map(int,input().split())
l=[int(i) for i in input().split()]
s=input()
i=0 
ans=0 
#import heapq as h 
while i<n:
    curr=s[i]
    c=0 
    a=[]
    sm=0 
    f= 0 
    #h.heapify(a)
    while i<n and s[i]==curr : 
        c+=1 
        a.append(l[i])
        i+=1 
    #print(len(a))
    #print(a)
    a.sort()
    ans+=sum(a[:k])
print(ans)