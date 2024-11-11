n = int(input())
r = input().split(' ')


def difficult(arr):
    d = 0
    for i in range(len(arr) - 1):
        l = int(arr[i + 1]) - int(arr[i])
        if l > d:
            d = l
    return d


mind = 100
for j in range(1, n - 1):
    q = r.copy()
    q.pop(j)
    rd = difficult(q)
    if rd < mind:
        mind = rd

print(mind)
