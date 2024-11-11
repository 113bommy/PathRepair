m,n=map(int,input().split())
a=list(map(int,input().split()))
b=list(set(a))
if len(b)<n:
    print("NO")
else:
    print("YES")
    c=b[0:n]
    e=[]
    for i in c:
        d=a.index(i)+1
        e.append(d)
    e=[str(u) for u in e]
    print(' '.join(e))
        
    
