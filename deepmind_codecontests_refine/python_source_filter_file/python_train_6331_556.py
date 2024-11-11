n, *a = map(int, open(0).read().split())
print(sum(a) - sorted(a)[-1])