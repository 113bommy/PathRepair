s=input()[::-1]
ans="No"
try:
  c=s.index("C")
  f=s.index("F")
  if c>f:
    ans="Yes"
except:
  pass
print(ans)