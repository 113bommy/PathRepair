l=-1; name='j'
for _ in range(int(input())):
  x=input().split()
  y=list(map(int, x[1:]))
  score=100*y[0]-50*y[1]
  for i in y[2:]:
    score+=i
  if score>l: l=score; name=x[0]
print(name)