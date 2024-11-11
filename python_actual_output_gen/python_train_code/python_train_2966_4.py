n, k, *h = map(int,open(0).read().split());
print(sum(h>=k for h_i in h))