a = list(map(int, input().split())).sorted()
print('Yes' if a[0] + a[1] == a[2] else 'No')