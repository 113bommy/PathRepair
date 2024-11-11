from sys import stdin


def arr_inp(n):
    if n == 1:
        return [int(x) for x in stdin.readline().split()]
    elif n == 2:
        return [float(x) for x in stdin.readline().split()]
    else:
        return list(stdin.readline()[:-1])


n, m = arr_inp(1)
mem = [0] * (m + 1)

for i in range(n):
    l, r = arr_inp(1)
    for j in range(l, r + 1):
        mem[j] = 1

all = []
for i in range(1, m):
    if not mem[i]:
        all.append(i)

print(len(all))
print(*all)
