import math
from collections import Counter
def sol():
    n=int(input())
    A=[int(i)for i in input().split()]
    for i in range(n):
        if(i==0):
            print(abs(A[i]-A[i+1]),abs(A[n-1]-A[0]))
        elif(i==n-1):
            print(abs(A[i]-A[i-1]),abs(A[n-1]-A[0]))
        else:
            print(max(abs(A[i]-A[0]),abs(A[i]-A[n-1])),min(abs(A[i]-A[0]),abs(A[i]-A[n-1])))
if(__name__=='__main__'):
    sol()
