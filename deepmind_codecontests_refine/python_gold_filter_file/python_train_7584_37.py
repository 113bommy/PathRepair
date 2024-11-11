d={c:list(input()) for c in "abc"}
s="a"
while d[s]:
  s=d[s].pop(0)
print(s.upper())