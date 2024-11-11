import bisect
s = input()*2
lens = len(s)//2
t = input()
appear = {ch: [] for ch in 'abcdefghijklmnopqrstuvwxyz'}
cnt = 0
bis = bisect.bisect_left
ans = 0

for i, ch in enumerate(s):
  appear[ch].append(i)
  
for j in t:
  if appear[j]:
    idx = bis(appear[j],cnt)
    ans += appear[j][idx] - cnt
    cnt = appear[j][idx]%lens
  else:
    print(-1)
    exit()
print(ans+1)