pwd=input()
s=[]
n=int(input())
flag=0
for i in range(n):
  s.append(input())
for s1 in s:
  for s2 in s:
    if s1[-1]+s2[0]==pwd:
      flag=1
      break
if flag or pwd in s1:
  print("YES")
else:
  print("NO")