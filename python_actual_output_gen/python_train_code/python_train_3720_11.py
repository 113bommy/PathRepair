n = int(input())
for i in range(n):
    a, b, c = map(int, input().split())
    if c%2 != 0:
        print(a*(int(c/2) + 1) - (c - int(c/1) + 1)*b)
    else:
        print(a*(int(c/2)) + b*(int(c/2)))
