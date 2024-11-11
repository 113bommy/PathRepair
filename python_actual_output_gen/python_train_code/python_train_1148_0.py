t = int(input())

for x in range(t):
    (n, k) = map(int, input().split())
    lst = []
    for y in input().split():
        lst.append(int(y))
    l = max(lst[0], n + 1 - lst[-1])
    for y in range(1, len(lst)):
        l = max(l, (lst[y] - lst[y - 1] - 1) // 2 + 1)
    print(l)
