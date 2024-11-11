x = list(map(int, input().split()))
x.sort()
print('Yes' if x[0]+x[1] == x[2] else 'No')