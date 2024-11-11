n, d = map(int, input().split())
lst = list(map(int, input().split()))

moves = 0
for i in range(1, len(lst)):
    if lst[i] <= lst[i - 1]:
        x = (lst[i - 1] - lst[i]) % d + 1
        lst[i] += x * d
        moves += x
print(moves)
