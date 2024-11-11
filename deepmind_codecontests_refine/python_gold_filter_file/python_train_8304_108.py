h, _ = map(int, input().split())
a = list(map(int, input().split()))
print('Yes' if sum(a) >= h else 'No')