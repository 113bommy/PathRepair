n=int(input())
a,b=map(int,input().split())
p=[int(i) for i in input().split()]
cnta=0
cntb=0
cntc=0
for i in p:
  if i<=a:
    cnta+=1
  elif i<=b:
    cntb+=1
  else:
    cntc+=1
print(cnta*cntb*cntc)