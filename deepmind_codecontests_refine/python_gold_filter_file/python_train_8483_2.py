a,b = map(int,input().split())
tempA,tempB = a,b
countA = 0
countB = 0
if a>b:
  countB = b
  a-=b
  if a%2 == 0:
    print(countB, a//2)
  else:
    print(countB,a//2)
elif a<b:
  countA = a
  b-=a
  if b%2 == 0:
    print(countA,b//2)
  else:
    print(countA,b//2)
else:
  print(a,0)