K = int(input())
A, B = map(int,input().split())

N = A // K
if (N+1) * K > B:
  print("NG")
else:
  print("OK")