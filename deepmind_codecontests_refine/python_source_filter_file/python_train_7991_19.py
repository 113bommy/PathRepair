n,k,*a = map(int,open(0).read().split())
def func(b):
  c = k
  for i in a:
    c -= i//b
    if c < 0:
      return False
  return True
l = 0
r = max(a)
while(r>l):
  lr = (l+r)//2
  if func(lr):
    r = lr
  else:
    l = lr + 1
print(r)