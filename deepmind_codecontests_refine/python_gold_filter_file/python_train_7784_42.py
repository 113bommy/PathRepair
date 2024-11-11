inf = 10**15
mod = 10**9+7
n,m = map(int, input().split())
tmp = n//2
for i in range(m):
    if i % 2 == 0:
        print('{} {}'.format(tmp-i//2, tmp+1+i//2))
    else:
        print('{} {}'.format(1+i//2, n-i//2-1))