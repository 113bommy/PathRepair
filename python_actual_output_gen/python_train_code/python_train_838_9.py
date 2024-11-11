N=int(input())
d,m=divmod(N,100)
print(['1','0'][m<=(d*5)])