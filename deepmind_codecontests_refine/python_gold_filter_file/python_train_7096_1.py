import sys
input = sys.stdin.readline
n,m = map(int,input().split())
tlr = [list(map(int,input().split())) for i in range(m)]
tlr.sort(key = lambda x:x[1])
srt = []
for t,l,r in tlr:
  if t == 0:
    continue
  if not srt:
    srt.append([l,r])
    continue
  if srt[-1][1] >= r:
    continue
  if srt[-1][1] >= l:
    srt[-1][1] = r
  else:
    srt.append([l,r])
ans = [10**8-i for i in range(n)]
for x,y in srt:
  for i in range(x,y):
    ans[i] = ans[i-1]+1
for t,l,r in tlr:
  if t == 0:
    if sorted(ans[l-1:r]) == ans[l-1:r]:
      print("NO")
      exit()
print("YES")
print(*ans)