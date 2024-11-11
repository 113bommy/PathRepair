a,v=list(map(int,input().split()))
b,w=list(map(int,input().split()))
t=int(input())
if w*t*(abs(a-b))<=v*t:
  print("YES")
else:
  print("NO")