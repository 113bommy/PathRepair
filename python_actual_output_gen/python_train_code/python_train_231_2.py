f = list(map(int,input().split()))
a = []
b = [0, 0, 0, 0]
for i in range(f[0]):
    a.append(list(map(int, input().split())))
for i in range(f[0]):
    if a[i][0] - f[1] > 0:
        b[0] += 1
    if a[i][0] - f[1] < 0:
        b[1] += 1
    if a[i][1] - f[2] > 0:
        b[2] += 1
    if a[i][1] - f[2] < 0:
        b[3] += 1
print(max(b))
if b[0]==max(b):
    print(f[1]+1, f[2])
elif b[1]==max(b):
    print(f[1]-1, f[2])
elif b[2]==max(b):
    print(f[1], f[2]+1)
elif b[3]==max(b):
    print(f[1]+1, f[2]-1)