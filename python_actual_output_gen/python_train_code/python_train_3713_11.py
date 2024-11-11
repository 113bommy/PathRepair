input()
n=input()
a=c=0
for i in n:
  if i=='I':a+=1
  else:a-=1
  c=max(a,c)
print(a)