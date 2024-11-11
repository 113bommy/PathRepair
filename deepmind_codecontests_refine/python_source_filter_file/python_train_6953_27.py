x=int(input())
for i in range(1,101):
  if x%i==0:
    if x%i<10:
      print('yes');exit()
      
print('no')