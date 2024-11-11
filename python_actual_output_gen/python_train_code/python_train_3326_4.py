n, a = map(int, input().split())
x = list(map(int, input().split()))
if n == 1:
    print(0)
elif n == 2:
    print(min(abs(a - x[0]), abs(a - x[1])))
else:
    num = float('inf')
    x = sorted(x)
    if a <= x[0]:
        num = min(num, abs(x[n - 1]))
    elif x[n - 1] <= a:
        num = min(num, abs(x[1]))
    num = min(abs(x[1] - a) + abs(x[1] - x[n - 1]), num)
    num = min(abs(x[n - 2] - a) + abs(x[0] - x[n - 2]), num)
    num = min(abs(x[n - 1] - a) + abs(x[n - 1] - x[1]), num)
    num = min(abs(x[0] - a) + abs(x[n - 2] - x[0]), num)
    print(num)
