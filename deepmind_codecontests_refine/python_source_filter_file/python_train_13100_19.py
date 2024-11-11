from collections import Counter

n = int(input())
A = list(map(int, input().split()))

c = Counter(A)
pair = []
print(c)
for x, cnt in c.items():
    pair += [x] * (cnt//2)

# print(pair)
pair.sort()

ans = 0
if len(pair) >= 2:
    ans = pair[-1] * pair[-2]
print ans