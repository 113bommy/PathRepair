n=int(input())
 
s=input()
l=len(s)
if l>n:
  print(s[:n].join('...'))
else:
  print(s)