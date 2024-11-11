a,b=map(int, input().split())
c=0
while a<=b:
  s=str(a)
  if s==s[::-1]:
    c+=1
  a+=1
print(c)
