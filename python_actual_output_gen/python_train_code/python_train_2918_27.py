a,b = map(int, input().split())
mi = min(a,b)
ma = max(a,b)
print("{} {}".format(mi, (ma-mi)/2))