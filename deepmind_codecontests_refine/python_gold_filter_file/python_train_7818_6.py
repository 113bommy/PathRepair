n, m = [int(x) for x in input().strip().split(" ")]

data = [[] for _ in range(105)]

for i in range(1, m + 1):
    a, b = [int(x) for x in input().strip().split(" ")]
    data[a].append((a, a * n + b))
    data[b].append((b, a * n + b))

for i in range(1, n + 1):

    print(len(data[i]) + 1)
    print(i, i)
    for a, b in data[i]:
        print(a, b)
