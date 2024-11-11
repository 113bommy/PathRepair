def ans():
  N = int(input())
  V = list(map(int,input().split()))
  even = [0]*100001
  odd = [0]*100001
  for v in V[1::2]:
    even[v] += 1
  for v in V[::2]:
    odd[v] += 1
  me = max(even)
  mo = max(odd)
  if(even.index(me) != odd.index(mo)):
    print(N - me - mo)
  else:
    even.sort()
    odd.sort()
    print(min(N-even[-1]-odd[-2], N-even[2]-odd[-1]))
ans()