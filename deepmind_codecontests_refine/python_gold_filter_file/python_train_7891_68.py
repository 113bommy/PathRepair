s=input()
li = []
for i in range(len(s)-2):
  li.append(abs(int(s[i:i+3])-753))
print(min(li))