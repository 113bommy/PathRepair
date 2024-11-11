n, m = map(int, input().split())
turn = [False] * (m + 1)
count = 0

for i in range(n):
    bulbs = list(map(int, input().split()))
    for x in bulbs[1:]:
        if not turn[x]:
            count += 1
            turn[x] = True

print('YES' if count == m else 'NO')