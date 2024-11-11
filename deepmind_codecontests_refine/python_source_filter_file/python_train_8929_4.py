N=int(input())
cnt = {}
for _ in range(N):
  s = input()
  if s not in cnt:cnt[s]=0
  cnt[s]+=1
max_val = max([cnt[v] for v in cnt])
l = [v for v in cnt if cnt[v]==max_val]
sorted(l)
print('\n'.join(l))