n = int(input())

N = n+2
mark = [2]*N


for i in range(2, N):
    if mark[i] == 2:
        for j in range(i*i, N, i):
            mark[j] = 1

print(len(set(mark[2:])))
print(*mark[2:])
