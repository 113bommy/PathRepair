import sys
input = sys.stdin.readline
q = int(input())
for i in range(q):
  n,s = input().split()
  n = int(n)
  direct = [0]
  for i in range(1,n-1):
    if s[i] != s[i-1]:
      direct.append(i)
  if s[-1] == ">":
    direct.append(n-1)
  l = len(direct)
  if l == 1:
    print(*list(range(1,n+1)))
    print(*list(range(1,n+1)))
    continue
  geq = []
  leq = []
  for i in range(1,l):
    if (i%2 and s[0] == ">") or (i%2 == 0 and s[0] == "<"):
      geq.append(direct[i]-direct[i-1])
    else:
      leq.append(direct[i]-direct[i-1])
  if s[0] == "<":
    geq.append(1)
    ans1 = []
    ans2 = []
    cnt = 0
    for i in range(l-1):
      if i%2 == 0:
        ans1.extend(list(range(n-cnt-leq[i//2],n-cnt+1)))
        cnt += leq[i//2]+1
      else:
        ans1.extend(list(range(n-cnt,n-cnt-geq[i//2]+1,-1)))
        cnt += geq[i//2]-1
    ans1.extend(list(range(1,n-cnt+1)))
    cnt = 1
    for i in range(l-1):
      if i == 0:
        ans2.extend(list(range(cnt,cnt+leq[i//2])))
        cnt += leq[i//2]
      elif i%2 == 0:
        ans2.extend(list(range(cnt,cnt+leq[i//2]-1)))
        cnt += leq[i//2]
      else:
        ans2.extend(list(range(cnt+geq[i//2],cnt-1,-1)))
        cnt += geq[i//2]
    ans2.extend(list(range(cnt+1,n+1)))
  else:
    ans1 = []
    ans2 = []
    cnt = 0
    for i in range(l-1):
      if i == 0:
        ans1.extend(list(range(n,n-geq[i//2],-1)))
        cnt += geq[i//2]
      elif i%2 == 0:
        ans1.extend(list(range(n-cnt,n-cnt-geq[i//2]+1,-1)))
        cnt += geq[i//2]-1
      else:
        ans1.extend(list(range(n-cnt-leq[i//2],n-cnt+1)))
        cnt += leq[i//2]+1
    ans1.extend(list(range(1,n-cnt+1)))
    cnt = 1
    for i in range(l-1):
      if i%2 == 0:
        ans2.extend(list(range(cnt+geq[i//2],cnt-1,-1)))
        cnt += geq[i//2]
      else:
        ans2.extend(list(range(cnt+1,cnt+leq[i//2])))
        cnt += leq[i//2]
    ans2.extend(list(range(cnt+1,n+1)))
  print(*ans1)
  print(*ans2)
