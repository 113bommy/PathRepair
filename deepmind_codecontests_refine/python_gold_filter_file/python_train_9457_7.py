n=int(input())
scr=[int(input()) for i in range(n)]
s=sum(scr)
if s%10!=0:
  print(s)
  exit()
scr.sort()
for i in range(n):
  if scr[i]%10!=0:
    print(s-scr[i])
    exit()
print(0)