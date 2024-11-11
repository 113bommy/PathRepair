h, w = map(int,input().split())
n = int(input())
A = list(map(int,input().split()))

color_row = []
for i,a in enumerate(A):
    color_row += [i+1 for _ in range(a)]


for i in range(h):
    if i%2 == 0:
        print(*color_row[w*i:w*i+5])
    else:
        print(*reversed(color_row[w*i:w*i+5]))
    