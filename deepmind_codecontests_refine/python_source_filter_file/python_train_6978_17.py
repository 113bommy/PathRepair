A = [[[0 for i in range(10)] for j in range(3)] for k in range(4)]

n = int(input())
for i in range(n):
    b,f,r,v = map(int,input().split())
    A[b-1][f-1][r-1] = v

for b in range(4):
    for f in range(3):
        for r in range(10):
            print('',A[b][f][r],end='')
        print()
    if i != 3:
        print('#'*20)