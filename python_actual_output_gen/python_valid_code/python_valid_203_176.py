t = int(input())
for _ in range(t):
    n, m = map(int, input().rstrip().split())
    if n == 1:
        print(0)
    elif n == 2:
        print(m)
    else:
        print(n+m)