t = int(input())
for _ in range(t):
    lastChar = "1"
    cnt = 0
    inp = input()
    n = len(inp)
    res = set()
    for i in range(n):
        if lastChar == inp[i]:
            cnt += 1
        else:
            if cnt % 2 == 1:
                res.add(lastChar)
            lastChar = inp[i]
            cnt = 1
        if i == n - 1 and cnt % 2 == 1:
            res.add(lastChar)
    sorted(res)
    print(*res, sep="")

