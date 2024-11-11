n, q = [int(el) for el in input().split(' ')]
data = [0] * n
result, index = 0, 1
for _ in range(q):
    a, v = [int(el) for el in input().split(' ')]
    data[a-1] += v
    if v > 0:
        if result < data[a-1]:
            result, index = data[a-1], a
        elif result == data[a-1]:
            index = min(index, a-1)
    else:
        if index == a:
            result = max(data)
            index = data.index(result) + 1
    print(index, result)