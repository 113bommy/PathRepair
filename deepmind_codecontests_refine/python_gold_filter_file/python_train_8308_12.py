from collections import Counter

n = int(input())
p = [int(input()) for _ in range(n)]

lst = [-1] * (n + 1)
for num in p:
    bfo = lst[num - 1]
    if bfo == -1:
        lst[num] = num
    elif bfo > 0:
        lst[num] = bfo
cnt = Counter(lst).values()
print(n - max(cnt))
