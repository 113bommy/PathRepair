h,w=map(int,input().split())
count=0
for i in range(h):
  a=input()
  count += a.count("#")
if count == h + w - 1:
  print("Possible")
else:
  print("Impossible")