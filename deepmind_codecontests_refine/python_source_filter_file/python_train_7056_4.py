s=input()
n=int(input())
front=""
back=""
reverse=False

for i in range(n):
  t=input().split()
  if t[0]=="1":
    reverse=not reverse
  else:
    if (t[1]=="1")^reverse:
      front=front+t[2]
    else:
      back=back+t[2]
if reverse:
  print(back[::-1]+s+front)
else:
  print(front[::-1]+s+back)
