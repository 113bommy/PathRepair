import math
t=int(input())
for i in range(t):
    n,x=map(int,input().split())
    arr=list(map(int,input().split()))
    mx=0
    for i in range(n):
        mx+=math.ceil(arr[i]/x)
    mi=math.ceil(sum(arr)/x)
    print(str(mx)+" "+str(mi))
