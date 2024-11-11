t = int(input())

while t > 0:
    n, s, k = (map(int, input().split()))
    print(n, s, k)
    a = map(int, input().split())
    mp = {}

    for x in a:
        mp[x] = 1

    mn = 123456
    for x in range(max(1, s - 2000), min(n + 1, s + 2000)):
        if x in mp:
            continue

        mn = min(mn, abs(s - x))

    print(mn)
    t -= 1
