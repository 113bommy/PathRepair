t,s,x=map(int,input().split())
if (x-t)%s==0 or (x-t)%s==1 and x-t!=1 and t-x<=0 :
    print('YES')
else:
    print('NO')
    