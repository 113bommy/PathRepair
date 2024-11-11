n,k=map(int,input().split())
if k==1:
    print(n)
else:
    k=int.bit_length(n)
    print((1<<k)-1)
