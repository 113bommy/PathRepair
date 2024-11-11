def inp(): return map(int,input().split())
n,k = inp()
print('YES' if n%k!=0 or n==k else 'NO')