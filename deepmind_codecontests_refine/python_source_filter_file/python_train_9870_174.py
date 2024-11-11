a,b=map(it,input().split())
p=0
if a>=13:
  p=b
elif a<=5:
  p=0
else:
  p=b//2
print(p)