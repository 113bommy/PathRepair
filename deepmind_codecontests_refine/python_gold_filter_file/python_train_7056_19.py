s1=list(input())
q=int(input())
s0=[]
f=1
for i in range(q):
  a=list(input().split())
  #print(i,a,s)
  if int(a[0])==1:
    f=(f+1)%2
  else:
    if (f+int(a[1]))%2==0:
      s0.append(a[2])
    else:
      s1.append(a[2])
if f==1:
  print("".join(s0[::-1])+"".join(s1))
else:
  print("".join(s1[::-1])+"".join(s0))
  