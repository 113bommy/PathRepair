from collections import Counter
N = int(input())
src = [eval(input()) for i in range(N)]
ctr = Counter(src)
ans = [ctr[a] for a in src]
print(*ans)
