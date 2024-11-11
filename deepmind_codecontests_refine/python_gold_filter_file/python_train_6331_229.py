N, *d = map(int, open(0).read().split())
print(int(sum(d)-max(d)/2))