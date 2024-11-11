from collections import Counter
n = int(input())
l = [int(input()) for _ in range(n)]
a= Counter(l).values()
print(sum(i for i in a if i%2))