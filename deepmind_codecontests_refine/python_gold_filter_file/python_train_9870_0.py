A,B=map(int,input().split())
if A<=5:
  ret=0
elif A>=13:
  ret=B
else:
  ret=B//2
print(ret)
