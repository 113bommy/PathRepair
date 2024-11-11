from collections import Counter

n = int(input())
v = list(map(int, input().split()))

if len(set(v)) == 1:
    print(n // 2)
    exit()

kisu = Counter(v[::2]).most_common(2)
gusu = Counter(v[1::2]).most_common(2)

if kisu[0][0] == gusu[0][0]:
    keep = max(kisu[1][1] + gusu[0][1],
               kisu[0][1] + gusu[1][1])
else:
    keep = kisu[0][1] + gusu[0][1]

print(n - keep)
