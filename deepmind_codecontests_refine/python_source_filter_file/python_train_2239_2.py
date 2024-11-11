ab, ac, bc = map(int, input().split())
route = 0 
if ab <= ac:
  route += ab
  if bc <= ab or ac > (ab+bc):
    route += bc
    if ac <= (bc + ab):
      route += ac
    else:
      route += (bc + ab) 
  else:
    route += ab 
    route += (ac + ac)
else:
  route += ac
  if bc <= ab:
    route += bc
    if ab <= (bc + ac):
      route += ab
    else:
      route += (bc + ac)
  else:
    route += (ac + ab)
    route += ab

print(route) 

