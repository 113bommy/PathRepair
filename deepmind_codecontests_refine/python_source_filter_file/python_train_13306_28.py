import math
L=int(input())

N=int(math.log(L,2))

print(N+1,bin(L-1)[2:].count("1")+2*N)


for i in range(1,N+1):
    print(i,i+1,0)
    print( i, i+1 , 2**(i-1) )


tmp=2**N
for i in range(N,0,-1):
    if tmp+2**(i-1)-1<=L-1:
        print(i,N+1,tmp)
        tmp=tmp+2**(i-1)