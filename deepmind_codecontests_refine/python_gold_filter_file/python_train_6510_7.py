from collections import Counter
n = int(input())
a = list(map(int, input().split()))

freq = Counter(a)

m = int(input())
b = list(map(int, input().split()))
c = list(map(int, input().split()))

best_index = 1
best_score = (0, 0)

for i in range(m):
    vs = freq[b[i]]
    als = freq[c[i]]
    if vs > best_score[0] or (vs == best_score[0] and als > best_score[1]):
        best_index = i + 1
        best_score = (vs, als)

print(best_index)
