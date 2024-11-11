n=input()
for i in ('+','-'):
  for j in ('+','-'):
    for k in ('+','-'):
      sm=a[0]+i+a[1]+j+a[2]+k+a[3]
      if eval(sm)==7:
        print(sm+'=7')
        exit()