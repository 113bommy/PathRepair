ss = list(input())
t = list(input())

ans = "UNRESTORABLE"
for i in range(len(ss) - len(t) + 1):
  flag = True
  for j in range(i, i + len(t)):
    if ss[j] != t[j-i] and ss[j] != "?":
      flag = False
      break
  if flag:
    ss[i:i+len(t)] = t
    ans = "".join(ss).replace("?", "a")
    break
    
print(ans)