n, a, b, c = [int(input()) for _ in range(4)]
if a <= b - c:
    print(n // a)
else:
    cnt = (n - c) // (b - c)
    print(cnt + (n - cnt * (b - c)) // a)