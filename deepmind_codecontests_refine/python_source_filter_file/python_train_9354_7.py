h,w=map(int,input().split())
A=[input().split() for _ in range(h)]
for a in range(h):
  for b in range(w):
    if A[a][b]=="snuke":
      print("{}{}".format(a+1,chr(ord("A")+b)))
      break
    