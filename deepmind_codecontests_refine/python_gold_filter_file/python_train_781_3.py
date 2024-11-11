def ke(i):
    return a[i-1]
n,k,q = map(int,input().split())
a = list(map(int,input().split()))
p = []
for i in range(q):
    b,id=map(int,input().split())
    id-=1
    if(b==1):
        p+=[id+1]
        p.sort(key=ke,reverse=True)
        if(len(p)>k):
            p=p[:-1]
    else:
        if id+1 in p:
            print('YES')
        else:
            print('NO')

