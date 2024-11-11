s=input()
t=[]
for i in range(len(s)-2):
  a=int(s[i:i+3])
  t.append(abs(a-753))
print(min(t))
