def eight_point_sets_2(s):
  x = list(set([a[0] for a in s]))
  x.sort()
  y = list(set([b[1] for b in s]))
  y.sort()
  print (x)
  print (y)
  test=True
  if len(x)!= 3 or len(y)!=3:
    test=False
    return test
  for i in range(0,3):
    for j in range(0,3):
      if i != 1 or j != 1:
        #print(x[i], y[j])
        if [x[i],y[j]] not in s:
          test=False
          break
  return test


l=[]
for i in range(8):
  this_point= [int(x) for x in input().split()]
  l.append(this_point)
result=eight_point_sets_2(l)
if result==True:
  print("respectable")
else:
  print("ugly")