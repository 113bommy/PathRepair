n = int(input())
s = input()
for i in range(1, n // 4 + 1):
  for j in range(i):
    if s[j::i].find("****") != -1:
      print("yes")
      exit()
print("no")