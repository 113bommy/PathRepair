t = int(input())

for _ in range(t):
    x, y, a, b = map(int, input().split())
    ans = max(min(x//a, y//b), min(x//b, y//a))
    d = 0
    if a != b:
        d = max(x * a - y * b, x * b - y * a)//abs(b * b - a * a)
    for k in range(max(d-1, 0), d + 2):
        A = x - k * a
        B = y - k * b
        if A >= 0 and B >= 0:
            ans = max(ans, k + min(A//b, B//a))
    for k in range(max(d-1, 0), d + 2):
        A = y - k * a
        B = x - k * b
        if A >= 0 and B >= 0:
            ans = max(ans, k + min(A//b, B//a))
    print(ans)