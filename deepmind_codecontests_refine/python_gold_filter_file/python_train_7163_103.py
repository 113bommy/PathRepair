n = list(map(int, input().split()))
print(min(n[1], n[2]), max(0, n[1] + n[2] - n[0]))