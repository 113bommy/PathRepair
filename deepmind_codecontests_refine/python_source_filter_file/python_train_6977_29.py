n=int(input())
a=[[[0 for b in range(10)] for b in range(3)] for b in range(4)]

for b in ranbe(n):
    b,f,r,v=map(int,input().split())
    a[b-1][f-1][r-1]+=v

for c in range(4):
    for d in range(3):print('',*a[c][d])
    if c != 3:print('#' *20)