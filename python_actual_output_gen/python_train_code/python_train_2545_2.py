s = int(input())

c=1

if s==2 or s==1 or s==4:
  print(3)
else:
  while s!=4:
    if s%2==0:
        s=s/2
    else:
        s=s*3+1
    c+=1
  print(c+3)