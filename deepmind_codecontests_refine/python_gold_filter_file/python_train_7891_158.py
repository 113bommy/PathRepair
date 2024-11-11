s = input()
a = 753
for i in range(len(s)-2):
  a = min(abs(int(s[i:i+3]) - 753),a)
print(a)