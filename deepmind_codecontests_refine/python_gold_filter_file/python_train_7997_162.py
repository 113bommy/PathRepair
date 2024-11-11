a, b = map(int, input().split())
m = a % b
if m == 0 or b == 1:
    print(-1)
else:
    print(a * (b + 1))