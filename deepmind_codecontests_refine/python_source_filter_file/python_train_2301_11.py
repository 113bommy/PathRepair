from collections import Counter
count = Counter()

n, k = map(int, input().split())
prib = [int(i) for i in input().split()]
res = 0
for i in prib:
    count[i] += 1
d = count.most_common(1)[0][1]
dic = dict(count)
if d % k == 0:
    for key, i in dic.items():
        res += i%d
else:
    d += k-(d % k)
    for key, i in dic.items():
        res += d-i%d
print(res)
