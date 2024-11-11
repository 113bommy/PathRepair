from collections import Counter

N, K = map(int, input().split())
A = list(map(int, input().split()))

li = Counter(A)
li = list(li.values())
li.sort()

sum(li[:max(len(li) - K, 0)])