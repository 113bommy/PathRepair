t = int(input())
for _ in range(t):
    n,m = list(map(int,input().split()))
    mat = []
    m1 = []
    for i in range(n):
        for j in range(m):
            if(i==0 and j==0):
                m1.append('B')
            else:
                m1.append('W')
        mat.append(m1)
        m1 = []
    for i in range(n):
        for j in range(m):
            print(mat[i][j],end = '')
        print('')