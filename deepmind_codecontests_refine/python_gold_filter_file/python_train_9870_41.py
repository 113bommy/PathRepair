a,b=map(int,input().split())
if a>=13:
  b=b
elif a>=6:
  b=b//2
else:
  b=0
print(b)