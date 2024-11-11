buckets = {chr(ord('A') + i): 0 for i in range(26)}
for c in (input() + input()):
    buckets[c] += 1

for c in input():
    buckets[c] -= 1

if sum([1 for v, k in buckets.items() if v == 0]):
    print('YES')
else:
    print('NO')