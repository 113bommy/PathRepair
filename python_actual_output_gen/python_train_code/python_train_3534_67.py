k = int(input())
a, b = map(int, input().split())
print('OK' if b - a + 1 >= k else 'NG')