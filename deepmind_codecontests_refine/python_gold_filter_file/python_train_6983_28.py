array = [[10*[0] for _ in [0]*3] for _ in [0]*4]
n = int(input())
for _ in range(n):
    a,b,c,d = map(int,input().split())
    array[a-1][b-1][c-1] += d
for i in range(4):
    for j in range(3): print('',*array[i][j])
    if i<3: print('#'*20)

