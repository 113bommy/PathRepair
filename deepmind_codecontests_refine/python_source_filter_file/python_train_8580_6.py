n, k = map(int, input().split())
trees = map(int, input().split())
deltas = [tree - i*k for i, tree in enumerate(trees)]
freqs = [0] * n
for delta in deltas:
    if delta >= 0:
        freqs[delta] += 1
d = freqs.index(max(freqs))
print(sum(((delta != d) for delta in deltas)))
for i, delta in enumerate(deltas):
    if delta > d:
        print("- %d %d" % (i+1, delta - d))
    elif delta < d:
        print("+ %d %d" % (i+1, d - delta))

