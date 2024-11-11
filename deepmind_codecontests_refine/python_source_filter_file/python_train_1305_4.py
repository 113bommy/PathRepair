a,b,d = map(int,input().split())
if d>0:
    if (b-a)/d == abs(int((b-a)/d)):
        print('YES')
    else:
        print('NO')

else:
    if b == a:
        print("YES")
        
    else:
        print('NO')