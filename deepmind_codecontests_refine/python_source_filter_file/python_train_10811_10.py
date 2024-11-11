input()
s =input()
a = []
n = 0
for i in s :
  if i == 'I':
    n +=1
  else :
    n-=1
  a.append(n)
print(max(a))