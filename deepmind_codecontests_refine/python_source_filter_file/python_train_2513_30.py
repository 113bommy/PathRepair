c=0
s=input()
for i,j in enumerate(s):
  j=int(j)
  if j%2==0:
    c=c+(i+1)
print(c)

