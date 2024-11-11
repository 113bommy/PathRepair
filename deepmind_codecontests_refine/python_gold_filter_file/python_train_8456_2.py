from math import log2,ceil
for _ in range(int(input())):
    N = int(input())
    for i in range(2,int(ceil(log2(N)))+1):
        if(N%((2**i)-1)==0):
            print(int(N/((2**i)-1)))
            break