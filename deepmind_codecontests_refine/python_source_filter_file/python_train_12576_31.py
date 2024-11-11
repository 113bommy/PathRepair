n =  int(input())
a,b,c,d = 0,0,0,0
for _ in [0]*n:
  s = input()
  if s[0] == "B" and  s[-1] == "A":
    d += 1
  elif s[0] == "B":
    b += 1
  elif s[-1] == "A":
    a += 1
  for i in range(len(s)-1):
    if s[i:i+2] == "AB":
      c += 1
if a == 0 and b == 0:
  c += min(d-1,0)
else:
   c += d + min(a,b)
print(c)