n,m = map(int,input().split())
if(n >= m//2):
    print(n)
else:
    m -= 2*n
    print(n + (m//4))