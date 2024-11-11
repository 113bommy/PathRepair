N, X, M = map(int,input().split())
if X==0:
  print(0)
  exit()
a = [X]
sa = set([X])
for i in range(1,N):
  X = (X**2)%M
  if X in sa:
    break
  else:
    a.append(X)
    sa.add(X)

if i==N-1:
  print(sum(a))
  exit()
start = a.index(X)
ans = sum(a[:start])
base = sum(a[start:])
rep = i-start
sets = (N-start)//rep
more = (N-start)%rep
ans += base*sets + sum(a[start:start+more])
print(ans)