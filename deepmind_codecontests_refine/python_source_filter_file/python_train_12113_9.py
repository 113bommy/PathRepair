x,t,a,b,da,db=map(int,input().split())
arr=[]
brr=[]
if x==0:
    print('YES')
elif x==a or x==b:
    print('YES')
elif x>a+b:
    print('NO')
else:
    arr.append(a)
    brr.append(b)
    for i in range(t-1):
        arr.append(a-da)
        a-=da
    for i in range(t-1):
        brr.append(b-db)
        b-=db
    ans  = False
    flag = True
    for i in range(len(arr)):
        if not flag:
            break
        for j in range(len(brr)):
            if not flag:
                break
            if arr[i]+brr[j]==x:
                ans=True
                flag=False

    if ans:
        print('YES')
    else:
        print('NO')
