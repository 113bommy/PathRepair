n = int(input())
a = list(input())
if n == 24:
  if a[0] > '2':
    a[0] = '0'
  elif a[0] == '2' and a[1] > '3':
    a[0] = '0'
else:  
  if a[0] > '1':
    if a[1] == 0:
      a[0] = '1'
    else:  
      a[0] = '0'
  elif a[0] == '1' and a[1] > '2': 
    a[0] = '0'
  elif a[0] == '0' and a[1] == '0':
    a[1] = '1'  
    
if a[3] > '5':
  a[3] = '0'
print("".join(a))  
    
