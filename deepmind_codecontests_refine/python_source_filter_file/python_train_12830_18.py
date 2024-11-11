import math
a=int(input())
for i in range(0,a):
    b=int(input())
    arr=list(map(int,input().split()))
    arr.sort()
    c=1
    for i in range(0,len(arr)):
        if(i+1>=arr[i]):
            c=i+1
    if(c==1):
        print(1)
    else:
        print(c+1) 
