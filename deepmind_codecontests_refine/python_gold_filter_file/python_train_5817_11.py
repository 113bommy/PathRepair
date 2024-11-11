t=""
for i in input():
  if i=="B":
    if len(t)!=0:
      t=t[:-1]
  else:t+=i
print(t)