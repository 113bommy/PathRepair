n,m = map(int,input().split())
if m==0:
    print(n-1)
    for i in range(1,1000):
        print(1000,i)
else:
    cond = []
    for i in range(m):
        ai,bi = map(int,input().split())
        cond.append(ai)
        cond.append(bi)
    for j in range(1,n+1):
        if j not in set(cond):
            break
    a=j
    print(n-1)
    for j in range(1,n+1):
        if j!=a:
            print(a,j)
            
        
        
        