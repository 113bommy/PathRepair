k=int(input())
a,b=map(int,input().split())
if a//k != b//k:
  print("OK")
else:
  print("NG")