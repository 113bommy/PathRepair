import math
N = int(input())
a = list(map(int,input().split()))
if min(a) >= 0:
    print(N-1)
    for i in range(N-1):
        print((i+1),(i+2))
elif max(a) <= 0:
    print(N-1)
    for i in range(N-1):
        print((N-i),(N-i-1))
else:
    if abs(max(a)) >= abs(min(a)):
        print(2*N-1)
        mindex = a.index(max(a))
        for i in range(N):
            print(mindex,i+1)
        for j in range(N-1):
            print((j+1),(j+2))
    else:
        print(2*N-1)
        mindex = a.index(min(a))
        for i in range(N):
            print(mindex,i+1)
        for j in range(N-1):
            print((N-j),(N-j-1))