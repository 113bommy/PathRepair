k2,k3,k5,k6=map(int,input().split())
no_of_256=min(k2,k5,k6)
k2-=no_of_256
k5-=no_of_256
k6-=no_of_256
no_of_32=min(k3,k6)
print(256*no_of_256+32*no_of_32)