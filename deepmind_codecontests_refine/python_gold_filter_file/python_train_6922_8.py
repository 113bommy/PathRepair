n,t = map(int,input().split())
k,m = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
if a[k-1] >= b[t-m]:
    print('NO')
else:
    print('YES')