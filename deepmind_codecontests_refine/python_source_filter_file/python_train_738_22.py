from collections import Counter
import math

def printArr(arr):
    for i in arr:
        print(i,end=" ")
        
def proA(n):
    if(n%2==0):
        return n//2
    i=2
    k=0
    while(True):
        
        if(i*i>n):
            break
        if(n%(i*i)==0):
            k=i
            break
        i+=1
    if(k==0):
        return 1
    return 1 + (n-k)//2
n=int(input())
print(proA(n))