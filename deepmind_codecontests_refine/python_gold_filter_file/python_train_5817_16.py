x = input()

for i in range(11):
  x=x.replace('1B', '')
  x=x.replace('0B', '')

x=x.replace('B', '')

print(x)