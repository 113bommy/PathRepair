num = int(input())

operations = []
value = 0
for i in range(num):
  expression = input('')
  operations.append(expression)

for j in operations:
  if j == '++x' or j == 'x++' or j == '+x+':
    value += 1
  elif j == '--x' or j == 'x--' or j == '-x-':
    value -= 1

print(value)
