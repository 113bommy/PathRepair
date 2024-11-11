s = int(input())
l = []
for i in range(len(s)-1):
  l.append(s[i:i+2])
print("Yes" if "AC" in l else "No") 