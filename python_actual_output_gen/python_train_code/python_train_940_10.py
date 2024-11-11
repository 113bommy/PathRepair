S=input()
L=['A','C','G','T']
no=0
x=0
for i in S:
  if i in L:
    x+=1
  else:
    x=0
  ans=(x,no)
print(ans)