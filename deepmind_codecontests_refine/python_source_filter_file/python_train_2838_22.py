t=int(input())
for _ in range(t):
    l=list(map(int,input().split()))
    
    if len(set(l))==3:
        print('NO')
    elif len(set(l))==1:
        print('YES')
        
        print(max(l),max(l),min(l))
    else:
        m=max(l)
        if l.count(m)==2:
            print('YES')
            print(m,m,min(l))
        else:
            print('NO')