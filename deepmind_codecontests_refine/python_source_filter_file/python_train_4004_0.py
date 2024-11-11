def s(x):
    r = 0;
    while x:
        r += x % 10
        x //= 10
    return r

a, b, c = map(int, input().split())
arr = []

for d in range(1, 73):
    x = b * d ** a + c
    if 0 < x < 1e9 and s(x) == d:
        arr.append(x)

arr.sort()
print(len(arr))
print(*arr)
