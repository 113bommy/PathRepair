L = sorted(list(map(int, input().split())))
print('Yes' if sum(L[:2]) == L[2] else 'No')