line = input().split()
n = int(line[0])
a = int(line[1])
b = int(line[2])

n -= a
if n > b:
  n = b + 1

print(n)