n, a, b = map(int, input().split())
t = list(map(int, input().split()))
newlist = []
for x in t:
  newlist += [((x*a)%b)//a]
print(*newlist)