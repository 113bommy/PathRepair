_, k, *h = map(int, open(0).read().split())
print(sum([i >= k for i in h]))