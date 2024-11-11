t,s,x =list(map(int,input().split()))
u=0
if x<t:
    print('NO')
elif x==t and u==0:
    print('YES')
elif t<x<t+s and u==0:
    print('NO')
else:
    p=x-t

    r = p%s

    if r==0 or r==1:
        print('YES')
    else:
        print('NO')
    

    
        
