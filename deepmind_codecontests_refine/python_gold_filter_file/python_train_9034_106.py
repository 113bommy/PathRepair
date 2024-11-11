s = input()
t = input()
x = 0
for i in range(3):
  x += s[i-1]==t[i-1]
print(x)