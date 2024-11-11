n = int(input())
a = [int(t) for t in input().split(' ')]

p = [0 for _ in range(n+1)]
for i in range(1, n+1):
    p[i] = p[i-1] ^ a[i-1]


counts = [{}, {}]
for t in range(2):
    for l in range(t, n+1, 2):
        counts[t][l] = counts[t].get(l, 0) + 1

count = 0

for t in range(2):
    cur_dict = counts[t]
    for v in cur_dict.values():
        count += (v * (v-1)) // 2

print(count)
