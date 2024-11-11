from itertools import permutations
n,m = map(int,input().split())
e = [tuple(sorted(map(int,input().split()))) for _ in range(m)]

ans = 0
for i in permutations(range(2, n+1), n-1):
  l = [1] + list(i)
  ans += sum(1 for j in zip(l, l[1:]) if tuple(sorted(j)) in e) == n-1

print(ans)