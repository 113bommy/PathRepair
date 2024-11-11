n=int(input())
def dsf(s):
  if int(s)>n:
    return0
  else:
    if all(s.count(c)>0 for c in "753"):
      x=1
    else:
      x=0
    for c in "753":
      x+=dsf(s+c)
    return x
print(dsf("0"))