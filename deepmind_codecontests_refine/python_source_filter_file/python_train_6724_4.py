#import sys
import math
#fin=open('d:\\1.txt')
arr=input().split()
a=int(arr[1])
b=int(arr[2])
n=input()
n=int(n)
i=0
res=0
arr=input().split()
while i<n:
    cur=int(arr[i])
    print(i, cur, a, b)
    if cur>a and cur<b:
        res+=1;
    i+=1;#python 不能++
print(res)


