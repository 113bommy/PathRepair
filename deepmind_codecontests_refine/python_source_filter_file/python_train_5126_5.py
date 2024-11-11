for i in range(int(input())):
    n,x=map(int,input().split())
    y=[int(w) for w in input().split()]
    
    z=sorted(list(set(map(int,y))))
    h=[0 for t in range(103)]
    for j in range(len(y)):
        h[y[j]-1]=1
    ans=0
    for l in range(len(h)):
        if h[l]!=1 and ans<x:
            ans+=1
            h[l]=1
            
    for q in range(len(h)):
        if h[q]!=1:
            break
    print(q)