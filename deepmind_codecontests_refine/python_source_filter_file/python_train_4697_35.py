a, b, c = sorted(map(int, input().split()))
print(min(0, c - a - b + 1))