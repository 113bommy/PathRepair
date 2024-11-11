from itertools import chain,accumulate

n,m,d = [int(i) for i in input().split()]
ls = [0]
for i in range(n):
  l=[int(i) for i in input().split()]
  ls = list(chain(ls,l))
for i in ls[1:]:
  if i%d != ls[1]%d:
    print(-1)
    exit()
ls.sort()
lsum = list(accumulate(ls))
ssum = lsum[len(ls)-1]
step = []
for i in range(1,len(ls)):
  x = ((ssum-lsum[i]-ls[i]*(len(ls)-1-i)) - (lsum[i-1]-ls[i]*(i-1)))//d
  step.append(x)
print(min(step))