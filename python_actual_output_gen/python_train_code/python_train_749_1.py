n = int(input())
R = list(map(int, input().split()))
c, i = 0, 1
for r in R:
  if r==i: i+=1
  else: c+=1
print(c if c<N else '-1')