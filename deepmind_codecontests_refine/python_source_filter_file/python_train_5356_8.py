n,m=map(int,input().split())
li=[]
for i in range(m):
 a=input()
 if not a in  li:
  li.append(a)
 else:
  print(i)
  exit(0)
else:
 print("-1")