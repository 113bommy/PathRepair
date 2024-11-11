k, s = map(int, input().split())
print(sum(s - (x + y) >= 0 for y in range(k + 1) for x in range(k + 1)))