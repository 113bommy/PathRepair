ss = {i:list(input()) for i in "abc"}
x = ss[a].pop(0)
while True:
  if not ss[x]:
    print(x.upper())
    break
  else:
    x = ss[x][0]