n=int(input())
ri=lambda: map(int, input().split(' '))
a=list(ri())
seen=set()
seen.add(0)
res=[0]
for x in a:
  res.append(res[-1]+x)
  if res[-1] in seen:
    import sys
    print(-1)
    sys.exit(0)
  seen.add(res[-1])
lo = min(res)
if lo<=0:
  lo = -1*lo + 1
  for i in range(len(res)):
    res[i] += lo
    
for x in res:
  if x>n:
    import sys
    print(-1)
    sys.exit(0)
  
buf=' '.join(list(map(str, res)))
print(buf)