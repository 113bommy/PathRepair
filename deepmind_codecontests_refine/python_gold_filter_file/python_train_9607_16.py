from sys import stdin
input = stdin.readline

def make_zero_2x2(y, x):
    zeros = []
    ones = []
    for i in range(2):
        for j in range(2):
            if a[y+i][x+j] == "0":
                zeros.append((y+i,x+j))
            else:
                ones.append((y+i,x+j))
                a[y+i][x+j] = "0"
    flip = []
    if len(zeros) == 0:
        flip.append([])
        for i in range(3):
            o = ones.pop()
            zeros.append(o)
            flip[-1].extend(o)
    for _ in range(2):
        if len(zeros) == 2 or len(zeros) == 3:
            flip.append([])
            o = ones.pop()
            flip[-1].extend(o)
            for i in range(2):
                z = zeros.pop()
                ones.append(z)
                flip[-1].extend(z)
            zeros.append(o)
    if len(zeros) == 1:
        flip.append([])
        for i in range(3):
            o = ones.pop()
            flip[-1].extend(o)
    return flip
    

t = int(input())
for _ in range(t):
    n, m = [int(x) for x in input().split()]
    a = [list(input().rstrip()) for _ in range(n)]
    ans = []
    for r in range(0, n, 2):
        for c in range(0, m, 2):
            if r + 1 < n:
                y = r
            else:
                y = r - 1
            if c + 1 < m:
                x = c
            else:
                x = c - 1
            flip = make_zero_2x2(y, x)
            if flip == []:
                continue
            for i in flip:
                ans.append([x + 1 for x in i])
    print(len(ans))
    for i in ans:
        print(*i)