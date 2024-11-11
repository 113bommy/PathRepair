n = input()[:-1]
while n[:len(n)//2] != [len(n)//2:]:
  n = n[:-1]
print(len(n))