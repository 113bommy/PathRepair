n=int(input())
 
s=input()
l=len(s)
if l>n:
  print(s[:n]+'...')
else:
  print(s)
