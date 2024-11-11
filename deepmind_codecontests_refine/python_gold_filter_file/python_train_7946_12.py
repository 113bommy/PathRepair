n, t1, t2, k = map(int, input().split())
k = (100 - k) / 100

from collections import defaultdict
result = defaultdict()
for i in range(n):
    a, b = map(int, input().split())
    result[i + 1] = max(b * t1 * k + t2 * a, a * t1 * k + t2 * b)

result = {k: v for k, v in sorted(result.items(), reverse=True, key=lambda item: item[1])}
for each in result.keys():
    print(each, "{:.2f}".format(result[each]))
