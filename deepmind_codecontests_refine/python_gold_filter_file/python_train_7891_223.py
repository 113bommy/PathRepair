a=input()
l=[]
for i in range(len(a)-2):
  l.append(abs(753-int(a[i:i+3])))
print(min(l))