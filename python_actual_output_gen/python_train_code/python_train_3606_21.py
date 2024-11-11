N,A,B,C,D=map(int,input().split())
S=input()[A-1:max(C,D)]

if "##" in S:
  print("No")
elif D>C:
  print("Yes")
else:
  if "..." in S[B-1:min(C,D)]:
    print("Yes")
  else:
    print("No")