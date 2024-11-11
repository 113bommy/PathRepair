n=int(input())
l=list(map(int,input().split()))
l1=list(map(int,input().split()))
l1=l1[::-1]
mi=0
V=[0]
L=[[] for i in range(n)]
for i in range(n-1) :
    a=l1[i]-1
    b=l1[i]-1
    s=l[l1[i]-1]
    if a-1!=-1 :
        if L[a-1] :
            s+=L[a-1][0]
            a=L[a-1][1]
    if b+1<n :
        if L[b+1] :
            s+=L[b+1][0]
            b=L[b+1][2]
    L[a]=[s,a,b]
    L[b]=[s,a,b]
    mi=max(mi,s)
    V.append(mi)
for i in range(n-1,-1,-1) :
    print(V[i])
    
    
    
