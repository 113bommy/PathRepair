n,l,r=map(int,input().split())
summ=2*l
summ+=(n-l)-1
summ2=(2**r)-1
summ2+=(n-r)*(2**(r-1))
print(summ,end=" ")
print(summ2)