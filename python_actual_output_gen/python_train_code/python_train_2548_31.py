n, *a = map(int, open(0).read().split())
print(sum(sorted(a)[1:n*2:2]))