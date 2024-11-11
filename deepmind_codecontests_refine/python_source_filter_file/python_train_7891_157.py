s = input()
a = 754
for i in range(len(s)-2):
  a = min(abs(int(s[i:i+3]) - 754),a)
print(a)