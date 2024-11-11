from collections import Counter

n = int(input())
p = [int(input()) for _ in range(n)]

lst = [False] * (n + 1)
for num in p:
    bfo = lst[num - 1]
    if bfo:
        lst[num] = num
    else:
        lst[num] = bfo
cnt = Counter(lst).values()
print(n - max(cnt))
