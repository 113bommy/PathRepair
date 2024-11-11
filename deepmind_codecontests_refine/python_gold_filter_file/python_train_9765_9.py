from collections import Counter
N = int(input())
c = Counter([tuple(sorted(input())) for _ in range(N)])
print(sum([(v*(v-1))//2 for v in c.values()]))