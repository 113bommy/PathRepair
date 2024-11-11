t=int(input())
for _ in range(t):
    l=[0]*10000
    n=int(input())
    y=list(map(int,input().split()))
    y.sort()
    for i in y :
        l[i-1]+=1
    test=True 
    for i in y :
        if l[i-1]%2==1:
            test=False
            break
    if test==False :
        print('NO')
    else :
        if n==1:
            print('YES')
        else :
            d=y[0]*y[-1]
            for i in range(n//2):
                if d!=y[-i-1]*y[i] or l[y[i]-1]!=l[y[-i-1]-1] :
                    test=False
            if test==False :
                print('NO')
            else :
                print('YES')
                