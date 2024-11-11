n = int(input())
a, b = map(int, input().split())
b = max(n - a, n - b)
w = max(a, b) - 1
if w <= b:
    print('White')
else:
    print('Black')
