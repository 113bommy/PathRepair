a,b,c,d=map(int,input().split())
a='Yes'
if abs(a-c)>d:
  if abs(a-b)>d or abs(b-c)>d:
    a='No'
print(a)