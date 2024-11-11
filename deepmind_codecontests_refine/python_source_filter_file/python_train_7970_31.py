n, k= map(int, input().split())
d = 240 - k
i = 0
while d >= i * 5 and n != 0:
    n -= 1
    d -= i * 5
    i += 1
print(i - 1)