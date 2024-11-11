n, t = map(int, input().split())
if n < 10:
    print("".join(str(t) for _ in range(n)))
elif t > 1:
    print("1" + "".join(str(t) for _ in range(n - 1)))
else:
    print(-1)
