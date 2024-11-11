from sys import stdin


def arr_inp(n):
    if n == 1:
        return [int(x) for x in stdin.readline().split()]
    elif n == 2:
        return [float(x) for x in stdin.readline().split()]
    else:
        return list(stdin.readline()[:-1])


n, k = arr_inp(1)
c = sorted(arr_inp(1))[::-1]

for i in range(min(n, k)):
    print(1, c[i])
    k -= 1

tem = []
for i in range(min(n - 1, k)):
    tem.append(c[i])
    for j in range(n - 1, i, -1):
        print(i + 2, end=' ')
        print(*(tem + [c[j]]))
        k -= 1
        if not k:
           exit()

