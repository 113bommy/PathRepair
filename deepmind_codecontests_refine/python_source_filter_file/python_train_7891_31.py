s=input()
l=[]
for i in range(len(s)-2):
  l.append(753-int(s[i:i+3]))
print(min(l))