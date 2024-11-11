n = int(input())
code = str(input())

decode = str()

for i in range(n):
  if (n - i) % 2:
    decode = decode + code[i]
  else:
    decode = code[i] + decode
  
  print(decode)