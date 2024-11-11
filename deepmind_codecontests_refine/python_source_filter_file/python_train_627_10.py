a, b, c = map(int, input().split())
s = list(map(lambda x: c % x, range(a, b)))
print(s.count(0))