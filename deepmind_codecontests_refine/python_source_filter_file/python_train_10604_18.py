s = input()
a = 'CODEFESTIVAL2016'
b = 0
for i in range(16):
  if a[i] != b[i]:
    b += 1
print(b)