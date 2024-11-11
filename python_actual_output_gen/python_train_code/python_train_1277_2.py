n=int(input())
s=input()
a,b,c=sorted((s.count(x),x) for x in "RGB")
if a[0] or b[0]>1:
  print("RGB")
elif b[0] or c[0]>1:
  print("".join(sorted(a[1]+b[1])))
elif b[0]:
  print(a[1])
else:
  print(c[1])