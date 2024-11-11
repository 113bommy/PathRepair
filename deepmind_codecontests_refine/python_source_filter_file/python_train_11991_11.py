s = input()
n = len(s)
t = input()
m = len(t)

rg = [0] * m 
j = m-1
for i in range(n):
  if s[n-1-i] == t[j]:
    rg[j] = n-1-i
    if j == 0:
      break
    j -= 1

lg = [0] * m
j = 0
for i in range(n):
  if s[i] == t[j]:
    lg[j] = i
    if j == m-1:
      break
    j += 1

mx = max(rg[0],n-1-lg[m-1])
for j in range(1, m):
  mx = max(mx, rg[j] - lg[j])
print(mx)