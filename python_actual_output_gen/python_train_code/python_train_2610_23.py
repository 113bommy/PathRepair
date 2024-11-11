s = {}
l = ["A","B","C"]
p = "A"
for x in l:
  s[x] = list(input().upper())
while True:
  if s[p] == []:
    print(p)
    break
  else:
    q = p
    s[p] = s[p][1:]
    p = q