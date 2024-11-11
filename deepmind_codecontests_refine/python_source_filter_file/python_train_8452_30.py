t = int(input())
for i in range(t):
    n, x, a, b = map(int, input().split())
    if (abs(a-b) + x) <= n:
        print(abs(a-b) + x)
        continue
    else:
        print(abs(a-b)+n-abs(a-b)-1)