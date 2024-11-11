n, m, k, l = map(int, input().split())
cn = (k+l +m-1) // m
if m*cn + k > n:
    print(-1)
else:
    print(cn)
