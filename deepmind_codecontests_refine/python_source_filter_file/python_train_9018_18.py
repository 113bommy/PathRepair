x, y = map(int, input().split())
res = (x - y + 1) >= 0 and (x - y + 1) % 2 == 0 and not (y == 0 and x != 0)
print('YES' if res else 'NO')