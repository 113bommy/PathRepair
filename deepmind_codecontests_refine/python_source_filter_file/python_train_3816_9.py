
R = lambda:map(int,input().split())

r, c = R()
arr = [input()+'.'for _ in[0]*r]+['.'*(c+1)]

ans = 0
for i in range(r):
    for j in range(c):
        t = arr[i][j+1], arr[i+1][j]
        s = arr[i][j]
        if (s == 'S' and 'W' in t or s == 'W' and 'S' in t):
            ans = 1

if ans:
    print('No')
else:
    print('Yes')
    for k in arr[:r]:
        print(k[:r].replace('.', 'D'))