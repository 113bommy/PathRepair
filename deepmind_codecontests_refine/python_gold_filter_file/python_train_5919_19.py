N,*A=map(int,open(0).read().split());f=a=0
for i,j in zip(A,A[1:]):
 if f:
  if(f<0)&(i<j)|(f>0)&(i>j):a+=1;f=0
 else:f=(i<j)-(i>j)
print(a+1)