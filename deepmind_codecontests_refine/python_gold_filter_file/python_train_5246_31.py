n = int(input())
fo = input()
r = 1
k = 1
if 'L' in fo and 'R' in fo : 

  for i,j in enumerate(fo,1) :
    if j == 'L' and k :
      t = i
      k = 0

    if j == 'R' and r : 
      s = i
      r = 0

  print(s,t)

elif 'R' not in fo :
 
  c = []
  for i,j in enumerate(fo,1) :
    if j == 'L' :
      c.append(i)

  print(c[-1],c[0]-1)

else : 
  c = []
  for i,j in enumerate(fo,1) :
    if j == 'R' :
      c.append(i)

  print(c[0],c[-1]+1)