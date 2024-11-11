a = input()
b = input()

# if two string are equals then they cant have uncommon substring
if a == b:
  print(-1)

# it is just the longer string that make the different
print(max(len(a), len(b)))