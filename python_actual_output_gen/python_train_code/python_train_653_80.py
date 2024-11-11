_, *a = map(int, open(0).read().split())
a.sort()
print(sum(a[-1::2]) - sum(a[-2::2]))
