f = set(range(0,3000,4))
h = set(range(0,3000,100))
fh = set(range(0,3000,400))
lp = (f -h).union(fh)
 
a = False
while True:
  f,l = list(map(int, input().split()))
  if f == 0 and l == 0:
    break
  if a:
    print (' ')
  t = set(range(f,l+1))
  it = sorted(list(lp.intersection(t)))
  for y in it:
    print(y)
  if len(it) == 0:
    print('NA')
  a = True