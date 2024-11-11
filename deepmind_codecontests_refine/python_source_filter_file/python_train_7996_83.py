s = input()
k = int(input())

i = 0

while s[i] == '1' and i < k:
  i += 1

print(int(s[i]))