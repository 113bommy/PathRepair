n = int(input())
ans = []
aa, bb = [False] * 90, [False] * 90
for i in range(1, n ** 2 + 1):
 a, b = map(int, input().split())
 if not aa[a] and not bb[b]:
  ans.append(i)
  aa[a] = True
  bb[b] = True
print(' '.join(map(str, ans)))