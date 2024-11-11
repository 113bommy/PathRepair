n,k=map(int,input().split())
if k==1: print(n)
else:
    a=int.bit_length(n)
    print((1<<a)-1)