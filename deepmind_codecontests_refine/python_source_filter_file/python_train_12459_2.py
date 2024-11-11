a = list(input())
b = list(input())
n = len(a)
r = 0
for i in range(n-1):
  if (a[i]=='0' and b[i]=='0'):
    if (a[i+1]=='0'):
      a[i+1], a[i], b[i] = 'x','x','x'
      r += 1
    elif (b[i+1]=='0'):
      b[i+1], a[i], b[i] = 'x','x','x'
      r += 1
  elif (a[i+1]=='0' and b[i+1]=='0'):
    if (a[i]=='0'):
      a[i+1], a[i+1], b[i] = 'x','x','x'
      r += 1
    elif (b[i]=='0'):
      b[i+1], a[i+1], b[i] = 'x','x','x'
      r += 1
print(r)