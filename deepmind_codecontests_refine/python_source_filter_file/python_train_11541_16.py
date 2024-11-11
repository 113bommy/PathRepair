A,B,C=map(int,input().split())
for i in range(2*B):
  if ((i*A)%B)==C:
    print("Yes")
    break
else:
  print("No")