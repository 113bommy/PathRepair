n, k= map(int, input().split())
b = n
d = 240 - k
i = 1
while d >= i * 5 and n != 0:
    n -= 1
    d -= i * 5
    i += 1
print(b - n)