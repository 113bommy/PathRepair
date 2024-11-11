H,W,h,w = map(int,input().split())
if not (H%h or W%w):
  print("No")
  exit()
if H%h:
  flg = "tate"
  n = H
  r = h
else:
  flg = "yoko"
  n = W
  r = w
ans = []
if r%2 == 0:
  s = r//2
  for i in range(n):
    if (i//s)%2 == 0:
      ans.append(2000)
    else:
      ans.append(-2001)
else:
  for i in range(n):
    if (i%r)%2 == 0:
      ans.append(2000)
    else:
      ans.append(-(int(2000/(r//2)*(r//2+1)))-1)
print("Yes")
if flg == "tate":
  for i in range(H):
    print(*([ans[i]]*W))
else:
  for i in range(H):
    print(*ans)