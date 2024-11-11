s = input()
k = int(input())

for i in map(int, s):
  if i != 1:
    print(i)
    break
else:
  print(1)