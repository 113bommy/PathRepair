import sys
t=int(sys.stdin.readline().strip())
for i in range(0,t):
    len=int(sys.stdin.readline().strip())
    array=list(map(int,sys.stdin.readline().strip().split()))
    m=min(array)
    k=1
    for j in array:
        if j!=m:
            k+=1
    print(k)
