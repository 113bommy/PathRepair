n, a, b = map(int, input().split())
print('{} {}'.format(max(a, b), max(0, n-a-b)))