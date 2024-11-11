n,t=map(int,input().split())
lis=[]
[lis.append(int(i)) for i in input().split()]
check=True
j=lis[0]
while check:
    if j+1==t:
        print('YES')
        check=False
    elif j>=n-1:
        print('NO')
        check=False
    else:
        j+=lis[j]
        if j+1==t:
            print('YES')
            check=False
        if j+1>t:
            print('NO')
            check=False