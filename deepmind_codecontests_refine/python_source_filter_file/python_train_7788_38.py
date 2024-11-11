from collections import Counter
n = int(input())
v = list(map(int, input().split()))
v1, v2 = v[::2], [1::2]
vv1 = Counter(v1).most_common()
vv2 = Counter(v2).most_common()

if len(set(v)) == 1:
    print(n//2)
if vv1[0] != vv2[0]:
    print(n - vv1[0][1] - vv2[0][1])
else:
    print(n - max(vv1[1][1] + vv2[0][1], vv1[0][1] + vv2[1][1]))