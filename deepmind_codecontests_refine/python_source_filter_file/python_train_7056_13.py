s=input()
q=int(input())

rev=1

sf=s
sb=""

for _ in range(0,q):
  n=input().split()
  if n[0]=="1":
    rev*=-1
  else:
    if (n[1]=="1" and rev==1) or (n[1]=="2" and rev==-1):
      sf+=n[2]
    else:
      sb+=n[2]

s=sf[::-1]+sb

if rev==1:
  print(s)
else:
  print(s[::-1])
