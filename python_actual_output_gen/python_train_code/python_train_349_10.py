def solve(inp, d):
    inp = sorted(inp, key=lambda x: x[0])
    p1 = 0
    p2 = 0
    n = len(inp)
    maxfnd = 0
    max1 = maxfnd
    while p2 < n:
        if inp[p2][0] - inp[p1][0] <= d:
            maxfnd += inp[p2][1]
            p2 += 1

        else:
            maxfnd -= inp[p1][1]
            p1 += 1
        max1 = max(max1, maxfnd)
    return max1


n, s = map(int, input().split())
in1 = []
for i in range(n):
    in1.append(list(map(int, input().split())))
print(solve(in1, s))
