n,k,l,c,d,p,nl,np=[int(x) for x in input().split()]
max1=k*l/nl 
max2=c*d
max3=p/np
print(min(max1,max2,max3)//n)
