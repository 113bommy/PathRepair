n, m = map(int, input().split())
c = m - 2*n
if c <= 0:
    print(m//2)
else:
    print(n + c//4)