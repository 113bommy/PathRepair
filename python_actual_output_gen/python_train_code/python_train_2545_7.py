s = int(input())
l=[]
count = 2

while s not in l:
  l.append(s)
  count+=1
  if s % 2 == 0:
    s = s//2
  else:
    s = 3*s+1

print(count)