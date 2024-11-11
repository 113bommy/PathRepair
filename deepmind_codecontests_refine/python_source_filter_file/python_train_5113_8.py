a,b=map(int,input().split())
c=list(map(int,input().split()))
d=list(map(int,input().split()))
e=[]
for j in range(a-1,-1,-1):
    e.append(int(d[j]))
if c[0]==1:
    if c[b-1]==1:
        print('YES')
    elif d[a-b]==1 and c[b-1]==0:
        k=0
        for i in range(a):
            if e[i]==1 and c[i]==1:
                k=1
        if k==1:
            print('YES')
        else:
            print('NO')
    else:
        print('NO')
else:
    print('NO')        
