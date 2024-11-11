n = int(input())
d = sorted(map(int, input().split()))
print(d[n // 2 + 1] - d[n // 2])