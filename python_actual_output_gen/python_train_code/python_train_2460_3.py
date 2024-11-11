t = int(input())

for _ in range(t):
    x, y, a, b = map(int, input().split())
    ans = max(min(x//a, y//b), min(x//b, y//a))
    d = 0
    if a > b:
        a, b = b, a
    if x > y:
        x, y = y, x
    if a != b:
        d = (x * b - y * a)//(b * b - a * a)
    
    for k in range(max(d, 0), d + 2):
        A = x - k * a
        B = y - k * b
        if A >= 0 and B >= 0:
            ans = max(ans, k + min(A//b, B//a))
    print(ans)