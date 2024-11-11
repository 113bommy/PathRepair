n = int(input())
ans = []
aa, bb = [False] * n, [False] * n
for i in range(1, n + 1):
 a, b = map(int, input().split())
 if not aa[a] and not bb[b]:
  ans.append(i)
  aa[a] = True
  bb[b] = True
print(' '.join(map(str, ans)))