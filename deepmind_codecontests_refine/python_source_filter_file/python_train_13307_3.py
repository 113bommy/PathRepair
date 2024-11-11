n=int(input())
l=[0]*5
m='MARCH'
for i in range(n):
  s=input()
  f=s[0]
  for i in range(5):
    if f==m[i]:
      l[i]+=1
      break
x=0
for i in range(3):
  for j in range(i+1,4):
    for k in range(j+1,5):
      x+=a[i]*a[j]*a[k]
print(x)