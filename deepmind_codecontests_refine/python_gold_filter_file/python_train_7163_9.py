n, a, b = map(int, input().split())
print('{} {}'.format(min(a, b), max(0, a+b-n)))