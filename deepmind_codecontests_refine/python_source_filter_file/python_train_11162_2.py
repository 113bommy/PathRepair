n=int(input())
a=[list(map(int,input().split())) for i in range(n)]
def notParallel(x,y):
    if x[0]==0 or y[0]==0:
        if x[0]==0 and y[0]==0:
            return False
        else:
            return True
    elif x[1]==0 or y[1]==0:
        if x[1]==0 and y[1]==0:
            return False
        else:
            return True
    elif x[0]!=y[0] or x[1]!=y[1]:
        return True
    return False
        
if len(a)%2==1:
    print('NO')
else:
    a.append(a[0])
    vs=[[] for i in range(n)]
    for i in range(n):
        vs[i]=[a[i+1][0]-a[i][0],a[i+1][1]-a[i][1]]
    n2=n//2
    for i in range(n2):
        ii,ni=vs[i],vs[i+n2]
        if notParallel(ii,ni):
            print('NO')
            break
    else:
        print('YES')
