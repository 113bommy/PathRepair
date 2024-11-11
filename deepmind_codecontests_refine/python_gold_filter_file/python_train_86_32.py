l = list(map(int, input().split()))

print('Yes' if max(l) * 2 == sum(l) else 'No')