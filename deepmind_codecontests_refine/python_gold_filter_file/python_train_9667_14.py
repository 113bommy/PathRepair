H, W=map(int, input().split())
cnt=0
for _ in range(H):
  a=list(input())
  cnt+=a.count("#")
if cnt==(H+W-1):
  print("Possible")
else:
  print("Impossible")
