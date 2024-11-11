k = ['AC','WA','TLE','RE']
n=int(input())
ans = {}
for _ in range(n):
  r = input()
  ans[r]=ans.get(r,0)+1
for r in k:
  print(r,'x',ans[r].get(r,0))
