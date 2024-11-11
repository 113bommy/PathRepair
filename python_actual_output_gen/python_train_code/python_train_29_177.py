a, b = map(int, input().split())
if (a or b) > 9:
    print(-1)
else:
    print(a * b)