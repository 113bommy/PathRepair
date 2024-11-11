n = int(n)
seq = [int(x) for x in input().split()]
d = round(sum(seq) / len(seq))
print(sum([(x-d)**2 for x in seq]))
