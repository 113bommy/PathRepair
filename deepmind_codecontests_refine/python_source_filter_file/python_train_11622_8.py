import re
n = int(input())

names = set()

for i in range(n):
  word = input()
  word = re.sub("k*h", "%", word)
  word = word.replace("u", "oo")
  names.add(word)
  
print(names)