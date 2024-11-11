def num(s,n,k):
  d,m,dm,dmc = 0,0,0,0
  for i in range(n,n*2):
    x,y = s[i],s[i-k]
    if y == 68:
      d -= 1
      dm -= m
    elif y == 77:
      m -= 1
    if x == 68:
      d += 1
    elif x == 77:
      m += 1
      dm += d
    elif x == 67:
      dmc += dm
  return dmc

def main():
  n = int(input())
  s = [0]*n + list(map(ord, list(input())))
  _ = input()
  l = list(map(int, input().split()))
  for k in l:
    print(num(s,n,k))

main()