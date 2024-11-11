n=int(input())
for h in range(1,(3*n)//4+1):
  for j in range(1,3501):
    if (4*h*j-j*n-n*h)>0 and 3500>=(n*h*j)/(4*h*j-j*n-n*h)>0 and ((n*h*j)/(4*h*j-j*n-n*h)).is_integer():
      print(h,j,(n*h*j)//(4*h*j-j*n-n*h))
      exit()