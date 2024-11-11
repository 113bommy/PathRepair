z = int(input())
while z:
    n, s, t = map(int, input().split())
    print((n - min(s, t)) + 1)
    z -= 1