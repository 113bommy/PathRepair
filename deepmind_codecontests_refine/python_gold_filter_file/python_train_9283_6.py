n=int(input())
if n%2==0:print('NO')
else:
    l1=[k for k in range(1,2*n+1) if k%4==0 or k%4==1]
    l2=[k for k in range(2*n+1) if k%4==2 or k%4==3]
    print('YES')
    print(*(l1+l2))


