N=int(input())
c=0
m=[]
s=input()
m.append(s)
for i in range(N-1):
  l=input()
  if l not in m and m[i][-1]==l[0]:
    c+=1
  m.append(l)
if c==N-1:
  print("YES")
else:
  print("NO")