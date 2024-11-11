import math

N = int(input().split()[0])
if N % 2:
    print (int((N-1)/2))
else:
    print(N - pow(2, int(math.log2(N))))