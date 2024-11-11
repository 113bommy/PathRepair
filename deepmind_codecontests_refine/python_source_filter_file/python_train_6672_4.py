#author : SanskarxRawat
a=10**10
for  i in range(int(input())):
  w,h=map(int,input().strip().split())
  if h<w:
   h,w=w,h
  if h<=a:
    a=h
  elif w<=h:
     a=w
  else: 
    print("NO")
    exit(0)
print("YES")