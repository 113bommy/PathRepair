def count(serials, start, end):
    return len(set(serials[start:end]))

t = int(input())

toprint = []

for tnum in range(t):
    n, k, d = list(map(int, input().split()))
    serials = list(map(int, input().split()))

    ans = d + 1

    for s in range(n - d + 1):
        ans = min(ans, count(serials, s, s + d))

    toprint.append(ans)

for i in toprint:
    print(i)