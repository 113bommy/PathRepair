n,m = input().split(' ')
l = [int(x) for x in input().split(' ')]
l.sort()
if sum(l) > l[-int(m)]*4*int(m):
  print("No")
else:
  print("Yes")
