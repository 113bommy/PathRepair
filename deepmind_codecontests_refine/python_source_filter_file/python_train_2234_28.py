n,m = map(int,input().split())
if m>n:
    print(-1)
elif m==n:
    print(m)
else:
    if n%2==0:
        minsteps = n/2
    else:
        minsteps = ((n-1)/2)+1
    for x in range(1,int(minsteps)+1):
        if (minsteps+x)%m==0:
            flag = True
            break
    if flag:
        print(minsteps+x)
    else:
        print(-1)