s = input()
n = len(s)
i = 0
pos = 0
while(i<n):
  if s[i:]==s[i:][::-1]:
    pos = i
    break
  i+=1
  
print(s+s[:pos][::-1])