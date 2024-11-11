W, a, b = map(int, input().split())
m = min(a, b)
M = max(a, b)
print(max(M-m-2*W, 0))