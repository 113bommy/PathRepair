n = input()
n = int(n)
sum = 0
res = 0
f = [0]*999
f[1] = 1
f[2] = 2
f[3] = 2
sum = 3
for i in range(3, n+1):
    f[i] = sum*2+1
    sum = f[i]
    if (f[i] >= n):
        res = i
        break
    if (f[i] > 1e9):
        break
f[3]=3
if (n > 3):
    print(res)
else:
    print(f[n])