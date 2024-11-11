import sys
import os

N, L = map(int,input().split())
A = list(map(int,input().split()))
for i in range(N-1):
    if A[i] + A[i+1] >= L:
        print("Possible")
        for j in range(i):
            print(j+1)
        for j in range(N-1,i,-1):
            print(j)
        sys.exit()
print("Impossible")
