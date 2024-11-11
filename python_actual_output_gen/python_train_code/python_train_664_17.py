n=int(input())
s=input().split()
for i in s:
  if int(i)<15: print("NO")
  else:
    q=int(i)%14
    if q<7: print("YES")
    else: print("NO")