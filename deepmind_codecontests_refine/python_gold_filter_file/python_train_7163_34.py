n, a, b = map(int, input().split())
print('{} {}'.format(min(a, b), max(a+b-n,0)))