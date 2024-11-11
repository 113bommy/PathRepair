n,m = map(int,input().split())
if(2*n >= m):
    print(m//2)
else:
    m -= 2*n
    print(n + (m//4))