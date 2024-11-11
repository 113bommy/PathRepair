t,s,x=map(int,input().split())
if x-t<0 or (x-t>0 and x-t<s):
    print('NO')
else:
    if x-t==0:
        print('YES')
    else:
        if (x-t)%s==1 or (x-t)%s==1:
            print('YES')
        else:
            print('NO')