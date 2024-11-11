s=input()
a=1000
for i in range(len(s)-2):
  x=int(s[i:i+3])
  a=min(a,abs(x-753))
print(a)