n, m = map(int, input().split())
a, b = (sum(x & 1 for x in map(int, input().split())) for _ in 'ab')
print(min(n - a, b) + min(n - b, a))