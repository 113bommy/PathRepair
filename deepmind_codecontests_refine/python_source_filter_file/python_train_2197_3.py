a,b,c=map(int,input().split())
l=list(map(int,input().split()))
l1=[(l[i],i) for i in range(a)]
otv=[0]*a
l1=sorted(l1,key=lambda x:x[0])
i=j=0
k=0
for i in range(a) :
    if l1[i][0]-c<=l1[j][0] :
        k+=1
        otv[l1[i][1]]=k
    else :
        otv[l1[i][1]]=otv[l1[j][1]]
        j+=1
print(" ".join(map(str,otv)))
        
