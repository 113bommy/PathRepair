h, n = map(int, input().split())
Ai = list(map(int, input().split()))
print('Yes' if h <= sum(Ai) else 'No')