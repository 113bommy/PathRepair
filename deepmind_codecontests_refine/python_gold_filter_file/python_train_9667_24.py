H,W=map(int,input().split())
c=0
for _ in range(H):
  c+=input().count("#")
print("Possible" if c==H+W-1 else "Impossible")