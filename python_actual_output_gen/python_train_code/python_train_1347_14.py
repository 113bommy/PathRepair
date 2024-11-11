n =int(input())
if (n == 4):
  print(1)
elif (n==7):
  print(2)
else:
  temp = n/10
  final_count = 0
  counter = 1
  
  while(temp != 0):
    final_count = final_count + (2**counter)
    temp = int(temp/10)
    counter += 1
  
  for i in range(counter):
    mod_val = 10**(i+1)
    curr_val = n % mod_val
    n = int(n / 10)
    if(curr_val == 7):
      final_count = final_count + (2**i)
  
  print(final_count+1)