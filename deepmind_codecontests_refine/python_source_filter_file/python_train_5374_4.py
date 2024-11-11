n=int(input())
l=list(map(int,input().split()))
L=[0]*200001
L1=[0]*200001
p=0
k=0
for i in range(n) :
    L[l[i]]+=1
for i in range(1,n+1) :
    if L[i]==0 :
        for j in range(p,n) :
            if i<l[j] and L[l[j]]>1 :
                L[l[j]]-=1
                k=k+1
                l[j]=i
                break
            if i>l[j] and L[l[j]]>1 and L1[l[j]]==1 :
                L[l[j]]-=1
                k=k+1
                l[j]=i
                break
            if i>l[j] and L[l[j]]>1 and L1[l[j]]!=1 :
                L1[l[j]]=1
        p=p+j
print(k)
print(*l)
            
                
                
                
                
    
            
    
