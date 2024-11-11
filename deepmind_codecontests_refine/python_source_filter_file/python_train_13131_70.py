x=input()
y=input()
if(x.lower()==y.lower()):
  print(0)
else:
  for i in range(len(x)):
    if(x[i].lower()>y[i].lower()):
      print(11)
      break
    else:
      if(x[i].lower()<y[i].lower()):
        print(-1)
        break  
