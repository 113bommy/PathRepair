n, p = map(int, input().split())
c = 1
while n:
    n -= p
    if n <= c:
        print(-1)
        break
    if bin(n).count('1') <= c:
        print(c)
        break
    c += 1