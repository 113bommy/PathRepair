n,m=map(int,input().split())
li=[]
for i in range(m):
 a=int(input())%n
 if not a in  li:
  li.append(a)
 else:
  print(i+1)
  exit(0)
else:
 print("-1")