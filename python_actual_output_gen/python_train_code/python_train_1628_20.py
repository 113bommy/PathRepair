n = list(map(int, input().split()))
if max(n) > sum(n) - max(n):
    print((max(n) - (sum(n) - max(n)) + 1))
else:
    print(0)
