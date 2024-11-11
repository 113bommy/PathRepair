n, k = map(int, input().split())

print(('NO', 'YES')[int(n / k % 2)])