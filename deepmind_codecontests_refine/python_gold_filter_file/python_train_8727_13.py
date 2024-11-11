N=int(input())
 
for h in range(1,3501):
  for n in range(1,3501):
    #divが負数ならwは負数になる
    if (4*h*n)-(N*n)-(N*h)>0:
      w=N*h*n/((4*h*n)-(N*n)-(N*h))
      if w.is_integer():
        print(h,n,int(w))
        exit()