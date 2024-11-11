n,k = map(int,input().split())
se = set()
ls = []
for i in range(n):
  s = input()
  se.add(s)
  ls.append(s)
anscnt = 0
for i in range(n-1):
  s = ls[i]
  for j in range(i,n):
    t = ls[j]
    ans = []
    for l in range(k):
      if s[l] == t[l]:
        ans.append(s[l])
      else:
        if s[l] == "S":
          if t[l] == "E":
            ans.append("T")
          else:
            ans.append("E")
        elif s[l] == "T":
          if t[l] == "E":
            ans.append("S")
          else:
            ans.append("E")
        else:
          if t[l] == "T":
            ans.append("S")
          else:
            ans.append("T")
    x = "".join(ans)
    if x in se:
      anscnt += 1
print(anscnt)