t = int(input())

for w in range(t):
    n, k, d = [int(i) for i in input().split()]
    a = [int(i) for i in input().split()]

    minAns = 10000

    if n == d:
        ans = list(set(a))
        print(len(ans))
        continue

    for i in range(n - d + 1):
        ans = set()
        for p in range(i, i + d):
            ans.add(a[p])

        if len(ans) < minAns:
            minAns = len(ans)

    print(minAns)