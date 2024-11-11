from collections import Counter
n = int(input())
cnt = Counter([int(x) for x in input().split()])
print('YES' if cnt.most_common(1)[0][1] <= n // 2 + 1 else 'NO')
