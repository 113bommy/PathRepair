n = int(input())
root = int(n**0.5)
for i in range(root):
  if n & (root-i) == 0:
    print(len(str( n // (root-i) )))
    break