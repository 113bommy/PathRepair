n = int(input())
a, b = map(int, input().split())
bl = max(n - a, n - b)
w = max(a, b) - 1
if w <= bl:
    print('White')
else:
    print('Black')
