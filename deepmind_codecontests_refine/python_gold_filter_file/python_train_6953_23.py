x=int(input())
for i in range(1,10):
  if x%i==0:
    if x/i<10:
      print('Yes');exit()
      
print('No')