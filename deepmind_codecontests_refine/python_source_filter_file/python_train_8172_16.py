from collections import defaultdict
d1 = defaultdict(int)
d2 = defaultdict(int)
n = int(input())
for i in range(n):
    l = list(map(lambda x: int(x) -1 ,input().split()))
    d1[l[0] + l[1]] += 1
    d2[l[0] - l[1]] += 1

total_ = 0
for v in d1.values():
    total_ += v * (v-1) / 2

for v in d2.values():
    total_ += v * (v-1) / 2

print(total_)