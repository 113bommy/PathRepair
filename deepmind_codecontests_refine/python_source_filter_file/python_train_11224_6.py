N = int(input())
A = list(map(int,input().split()))
if A == sorted(A) and len(A) == len(set(A)):
  print(1)
  exit(0)

def check(X):
  idx = [0]
  ltr = [0]
  for a in A:
    if idx[-1] < a:
      idx.append(a)
      ltr.append(0)
    else:
      while True:
        while idx[-1] > a:
          idx.pop()
          ltr.pop()
        if idx[-1] != a:
          idx.append(a)
          ltr.append(0)
        if idx[-1] == 0:
          return False
        ltr[-1] += 1
        if ltr[-1] < X:
          break
        a = idx[-1] - 1
        idx.pop()
        ltr.pop()
  return ltr[0] == 0

t = [0, N]
while t[1] - t[0] > 1:
  mid = (t[0] + t[1]) // 2
  t[check(mid)] = mid
print(t[1])
