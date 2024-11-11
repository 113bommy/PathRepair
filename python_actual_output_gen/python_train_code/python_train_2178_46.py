n,k=map(int,input().split())
if n==k and k==1:
    print('YES')
else:
    print('YES' if (n%k)%2==1 else 'NO')