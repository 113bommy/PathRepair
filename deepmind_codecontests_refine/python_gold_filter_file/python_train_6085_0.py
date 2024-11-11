n, m = map(int, input().split())

data = [[0, i] for i in range(min(m + 1, 5))] + [[j, 0] for j in range(min(n + 1, 5))] + [[n, k] for k in range(max(0, m - 5), m + 1)] + [[l, m] for l in range(max(n - 5, 0), n + 1)]
a, b, c, d = 0, 0, 0, 0
r = -1

def check(a, b, c, d):
    return ((a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2) ** 0.5 + ((b[0] - c[0]) ** 2 + (b[1] - c[1]) ** 2) ** 0.5 + ((c[0] - d[0]) ** 2 + (c[1] - d[1]) ** 2) ** 0.5
for i in range(len(data)):
    for j in range(len(data)):
        for k in range(len(data)):
            for l in range(len(data)):
                if not (data[i] != data[k] and data[j] != data[l] and data[i] != data[j] and data[i] != data[l] and data[j] != data[k] and data[k] != data[l]):
                    continue
                if r < check(data[i], data[j], data[k], data[l]):
                    r = check(data[i], data[j], data[k], data[l])
                    #print(i, j, k, l)
                    a, b, c, d = data[i], data[j], data[k], data[l]
print(a[0], a[1])
print(b[0], b[1])
print(c[0], c[1])
print(d[0], d[1])
