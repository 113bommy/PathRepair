N = int(input())
for h in range(1,3501):
  for n in range(1,3501):
    if 4*h*n!=(N*n)+(N*h):
      w=(N*h*n)//((4*h*n)-(N*n)-(N*h))
      if 4*h*n*w==N*(n*w+h*w+n*h) and w>0:
        break
  else:
    continue
  break
print(h,n,w)
      
