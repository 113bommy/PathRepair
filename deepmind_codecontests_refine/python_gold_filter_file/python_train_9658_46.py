_, *a = map(int, open(0).read().split())
print(sum(b%2 for b in a[::2]))