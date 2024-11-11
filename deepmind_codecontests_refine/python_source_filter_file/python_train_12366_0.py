def f(nums, K, w):
  h=len(nums)
  counter=[nums[x][0] for x in range(h)]
  if max(counter)>K:
    return float('inf')
  
  out=0
  for i in range(1, w):
    for x in range(h):
      counter[x]+=nums[x][i]
      
    if max(counter)>K:
      out+=1
      counter=[nums[x][i] for x in range(h)]
      
  return out

H, W, K=map(int, input().split())
S=[input() for _ in range(H)]
S=[[int(S[i][j]) for j in range(W)] for i in range(H)]
ans=float('inf')
for p in range(2**(H-1)):
  q='0'+format(p, '0'+str(H-1)+'b')+'1'
  i=0
  c=0
  nums=[]
  while i<H:
    j=1
    while i+j<H and q[i+j]=='0':
      j+=1
    tmp=S[i:i+j]
    nums.append([sum([tmp[y][x] for y in range(j)]) for x in range(W)])
    i+=j
    
  cand=f(nums, K, W)+q.count('1')-1
  if ans>cand:
    ans=cand
    
print(ans)

