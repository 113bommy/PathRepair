from itertools import combinations
N = int(input())
d = [0]*128
for _ in range(N): dic[ord(input()[0])] += 1
print(sum([d[ord(p0)]*d[ord(p1)]*d[ord(p2)] for p0,p1,p2 in combinations('MARCH', 3)]))
