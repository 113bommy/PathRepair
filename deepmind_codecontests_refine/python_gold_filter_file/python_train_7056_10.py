s = input()
q = int(input())
s1 = ""
s2 = ""
cnt = 1
for i in range(q):
  l1 = list(input().split())
  if len(l1) == 1:
    cnt *= -1
  else:
    if (cnt == 1 and l1[1] == "1") or (cnt == -1 and l1[1] == "2"):
      s1 = l1[2] + s1
    else:
      s2 = s2 + l1[2]
if cnt == 1:
  print(s1+s+s2)
else:
  print(s2[::-1]+s[::-1]+s1[::-1])