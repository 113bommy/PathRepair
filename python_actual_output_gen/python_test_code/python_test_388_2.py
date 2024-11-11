n,x=map(int, input().split())
l=list(map(int, input().split(' ')))
nl=[i for i in range(0,max(max(l)+2,x)) if not( i in l )]
if x in nl:
    d=len([i for i in nl if i<x])
else:
    if max(l)+2>x:
        d=len([i for i in nl if i<x])+1
    else:
        d=len(nl)+1
print(d)
    
