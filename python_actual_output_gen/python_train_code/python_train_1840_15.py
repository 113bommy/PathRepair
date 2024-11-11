t = int(input())
while t:
    n, s, t = map(int, input().split())
    print((n - min(s, t)) + 1)
    t -= 1