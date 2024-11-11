n,a,b,*h=map(int,open(0).read().split());i,j=0,2**30
while j-i>1:
 k=c=(j+i)//2
 for t in h:c-=max(0,(t-b*k)/(a-b))
 if c<0:i=k
 else:j=k
print(j)