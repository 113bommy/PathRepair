n, k = map(int, input().split())
x = list(map(int, input().split()))
x.sort()
try:
    if k > 1:
        print(x[-k] - 1, x[-k] - 1)
    else:
        print(x[-k], x[-k])
except IndexError:
    print(-1)
