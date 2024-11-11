import sys
input = sys.stdin.buffer.readline
n = int(input())
a = list(map(int,input().split()))
if sum(a) == 1:
  print(-1)
  exit()
sm = sum(a)
nmax = 10**6+10
eratos = [0 for i in range(nmax+1)]
prime = []
cnt = 2
while True:
  while cnt <= nmax and eratos[cnt]:
    cnt += 1
  if cnt > nmax:
    break
  eratos[cnt] = 1
  prime.append(cnt)
  for i in range(cnt**2,nmax+1,cnt):
    eratos[i] = 1
dvls = set()
for i in prime:
  while sm%i == 0:
    dvls.add(i)
    sm //= i
if sm != 1:
  dvls.add(sm)
ansls = []
ls = []
for dv in dvls:
  cnti = 0
  ans = 0
  if dv == 2:
    for i in range(n):
      if a[i]%2:
        cnti += 1
        if cnti%2:
          pivot = i
        else:
          ans += i-pivot
  else:
    flg = 0
    for i,ai in enumerate(a):
      rai = ai%dv
      if rai:
        cnti += rai
        if 1 <= cnti <= dv//2:
          ls.append((i,rai))
        elif not flg:
          pivot = i
          while ls:
            j,num = ls.pop()
            ans += (pivot-j)*num
          if cnti < dv:
            flg = 1
            need = dv-cnti
          else:
            cnti -= dv
            ls.append((pivot,cnti))
        else:
          if cnti >= dv:
            ans += (need)*(i-pivot)
            cnti -= dv
            if cnti <= dv//2:
              flg = 0
              if rai-need:
                ls.append((i,rai-need))
            else:
              pivot = i
              need = dv-cnti
          else:
            ans += rai*(i-pivot)
            need -= rai
  ansls.append(ans)
print(min(ansls))