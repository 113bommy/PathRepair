n=int(input())
a=list(map(int,input().split()))
x=list(set(a))
x.sort()
if len(x)==3 :
    if 2*x[1] ==x[0]+x[2]:
        print('YES')
    else:
        print('NO')
elif len(x)<3:
    print('YES')
else:
    print('NO')