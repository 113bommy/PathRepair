N = int(input())
S = []
C = []
for _ in range(N):
  s, c = input().split()
  C.append(int(c))
  S.append(tuple(ord(c) - ord('a') for c in s))
#print(S)
INF = 10**30
dp = {}
def min_cost(l, r):
  if (l, r) in dp:
    return dp[(l, r)]
  if l and l == l[::-1]:
    dp[(l, r)] = 0
    return dp[(l, r)]
  if r and r == r[::-1]:
    dp[(l, r)] = 0
    return dp[(l, r)]
    
  #print(l, r)
  dp[(l, r)] = INF
  if not l:
    for c, s in zip(C, S):
      if len(s) > len(r):
        if s[len(s)-len(r):] == r:
          dp[(l, r)] = min(dp[(l, r)], c + min_cost(s[:len(s)-len(r)][::-1], () ))
      elif len(s) == len(r):
        if s == r:
          dp[(l, r)] = min(dp[(l, r)], c)
      else:
        if s == r[len(r)-len(s):]:
          dp[(l, r)] = min(dp[(l, r)], c + min_cost((), r[:len(r)-len(s)]))
        
  if not r:
    for c, s in zip(C, S):
      if len(s) > len(l):
        #print('equal', s[:len(l)] , l)
        if s[:len(l)] == l:
          dp[(l, r)] = min(dp[(l, r)], c + min_cost((), s[len(l):][::-1] ))
      elif len(s) == len(l):
        if s == l:
          dp[(l, r)] = min(dp[(l, r)], c)
      else:
        if s == l[:len(s)]:
          dp[(l, r)] = min(dp[(l, r)], c + min_cost(l[len(s):], ()))
        
  return dp[(l, r)]
        
  
m = min_cost((), ())
for s, c in zip(S, C):
  if s == s[::-1]:
    m = min(m, c)
if m == INF:
  print(-1)
else:
  print(m)