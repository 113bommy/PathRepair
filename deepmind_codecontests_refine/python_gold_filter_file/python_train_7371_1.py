s = int(input())

c=1

if s==2 or s==1:
  print(4)
else:
  while s!=4:
    if s%2==0:
        s=s/2
    else:
        s=s*3+1
    c+=1
  print(c+3)