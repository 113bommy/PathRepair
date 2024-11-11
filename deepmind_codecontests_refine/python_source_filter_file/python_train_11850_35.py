N,M = map(int,input().split())

ave = M//N
amari = M%N
while True:
  if amari%ave == 0:
    ans = ave
    break
  else:
    ave -= 1
    amari = M%ave
print(ans)  