n,t,k,d=[int(x) for x in input().split() ]
x=(int(d/t)+1)*k
rest=n-k
if rest >= 1:
    print('YES')
else:
    print('NO')