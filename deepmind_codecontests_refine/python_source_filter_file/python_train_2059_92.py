A,V=map(int,input().split())
B,W=map(int,input().split())
T=int(input())
v=V-W
l=abs(A-B)

if l<=V*T:
  print("YES")
else:
  print("NO")