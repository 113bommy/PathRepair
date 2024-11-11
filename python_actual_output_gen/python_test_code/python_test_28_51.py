n=[str(i) for i in input()]
count=0
for x in range(len(n)):
  if ord(n[x])<97:
    count+=1
f=''.join(n)
if count>=(len(n)+1)//2:
  print(f.upper())
else:
  print(f.lower())
