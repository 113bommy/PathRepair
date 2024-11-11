s1, s2 = [i for i in input().split(' ')]
str = s1 + s2
for i in range(1, len(s1)):
  for j in range(1, len(s2)):
    var = s1[0:i] + s2[0:j]
    if var < str:
      str = var
print(str)