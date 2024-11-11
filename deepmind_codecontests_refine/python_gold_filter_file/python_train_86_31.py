arr = list(map(int, input().split()))
print('Yes' if max(arr) * 2 == sum(arr) else 'No')