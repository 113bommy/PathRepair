s=int(input());
for n in range(3501):
 for h in range(3501):
  x=4*h*n-s*n-s*h
  if x>0:
   if ((s*h*n)/x).is_integer():
    print(int((s*h*n)/x),h,n)
    exit()