N = int(input())
n = [ map(int, input().split()) for i in range(N) ]
kousya = [ [[0]*10 for i in range(3)] for j in range(4) ]
for b, f, r, v in n:
    kousya[b-1][f-1][r-1] = v
for i in range(4):
    for j in range(3):
        print(*kousya[i][j])
    else:
        if i == 3: break
        print('#' * 20)
