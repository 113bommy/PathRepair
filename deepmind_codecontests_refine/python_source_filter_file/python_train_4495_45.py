a = input()
x = []
for i in a:
  if i.isupper():
      i = i.lower()

  if i in ['a','e','i','o','u']:
    continue
  else:
    x.append('.')
    x.append(i)
s = ''.join(x)     

print(s)    