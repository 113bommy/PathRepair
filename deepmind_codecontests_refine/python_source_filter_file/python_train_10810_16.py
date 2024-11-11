n = input()
num = len(s)-2
for i in range(num,0,2):
  f = int(i/2)
  if s[:f]==s[f:i]:
    print(i)
    break