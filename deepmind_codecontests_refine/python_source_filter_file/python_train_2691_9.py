n,a,b,*h=map(int,open(0).read().split());i,j=0,2**47
while j-i>1:
 k=c=(j+i)//2
 for t in h:c+=min(0,(b*k-t)//(a-b))
 if c<0:i=k
 else:j=k
print(j)