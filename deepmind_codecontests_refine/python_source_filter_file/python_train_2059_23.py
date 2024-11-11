A, V = map(int,input().split())
B, W = map(int,input().split())
T    = int(input())

if abs(V-W)*T >= A-B:
  print("YES")
else:
  print("NO")
#