n,k=map(int,input().split())
if n==k and n==1:
    print('YES')
else:
    print('YES' if (n//k)%2==1 else 'NO')