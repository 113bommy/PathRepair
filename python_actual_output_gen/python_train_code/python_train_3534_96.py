k = int(input())
a, b = map(int, input().split())

print('OK' if b - a >= k else 'NG')