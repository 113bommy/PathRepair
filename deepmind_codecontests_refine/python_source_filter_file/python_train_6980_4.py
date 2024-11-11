a = [[[0 for i in range(10)] for j in range(3)] for k in range(4)]
e = '#' * 20
n = int(input())
for i in range(n):
    b,f,r,v = [int(i) for i in input().split()]
    a[b - 1][f - 1][r - 1] += v
for i in range(4):
        for j in range(3):
            print(' '.join(map(str,a[i][j])))
        if(i != 3):
            print(e)