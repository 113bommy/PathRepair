c = list(map(int, input().split()))
print('Yes' if max(c)*2 == sum(c) else 'No')