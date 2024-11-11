n,m = map (int, input().split())
print (n+m-1)
boys = list (range (1, n+1))
girls = list (range (1, m+1))
path = list (zip (boys, girls))
path += list (zip (boys, girls[1:]))
if n < m:
  path += [(n,i) for i in girls[n+1:]]
else:
  path += [(i,m) for i in boys[m+1:]]
path.sort()
for x,y in path:
  print (x,y)
