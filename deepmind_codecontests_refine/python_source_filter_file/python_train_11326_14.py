H, W, A, B = map(int, input().split())

t = [[0]*A + [1]*(W-A)]*B + [[1]*A + [0]*(W-A)]*(H-B)

for t_i in t:
    print(*t_i)
