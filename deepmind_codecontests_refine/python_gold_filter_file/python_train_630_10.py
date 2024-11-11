a, b, c = map(int, input().split())
s = list(map(lambda x: c % x, range(a, b+1)))
print(s.count(0))