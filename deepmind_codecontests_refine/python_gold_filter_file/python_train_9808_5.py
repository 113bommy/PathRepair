def ans(data):
    data.sort()
    res = float('+inf')
    for i in range(-1, 2):
        for j in range(-1, 2):
            for k in range(-1, 2):
                res = min(res, abs(data[0] + i - j - data[1]) + abs(data[0] + i - k - data[2]) + abs(data[1] + j - k - data[2]))
    return res


n = int(input())
for i in range(n):
    inp = list(map(int, input().split()))
    print(ans(inp))
