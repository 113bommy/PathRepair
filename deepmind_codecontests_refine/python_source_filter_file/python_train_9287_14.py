from math import ceil
for _ in range(int(input())):
    n,d=map(int,input().split())
    z=min(n,10000)
    flag=0
    if n>=d:
        print('YES')
        continue
    for x in range(1,z+1):
        if ceil(d/(x+1))<=(n-x):
            print('YES')
            flag=1
            break
    if flag==0:
        print('NO')