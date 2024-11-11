x, y = map(int, input().split())
c = [0]*205
c[1], c[2], c[3] = 3, 2, 1
reword = c[x]+c[y]
if x+y == 2:
    reword += 4

print(reword*100000)
