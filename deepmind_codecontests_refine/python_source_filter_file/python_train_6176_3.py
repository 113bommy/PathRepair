def arr_inp():
    return [int(x) for x in stdin.readline().split()]


from sys import stdin

n, m = arr_inp()
initial, k = arr_inp(), int(input())
vectors, ans = [arr_inp() for i in range(k)], 0
for i in range(k):
    mi = []
    if vectors[i][0] > 0:
        mi.append((n - initial[0]) // vectors[i][0])
    elif vectors[i][0] < 0:
        mi.append((initial[0] - 1) // abs(vectors[i][0]))
    else:
        mi.append(-1)

    if vectors[i][1] > 0:
        mi.append((m - initial[1]) // vectors[i][1])
    elif vectors[i][1] < 0:
        mi.append((initial[1] - 1) // abs(vectors[i][1]))
    else:
        mi.append(-1)

    if mi[0] != -1 and mi[1] != -1:
        ans += min(mi)
        initial[0] += (vectors[i][0] * min(mi))
        initial[1] += (vectors[i][1] * min(mi))
    elif mi[1] == -1 and mi[0] != -1:
        ans += mi[0]
        initial[0] += (vectors[i][1] * mi[0])
    elif mi[0] == -1 and mi[1] != -1:
        ans += mi[1]
        initial[1] += (vectors[i][1] * mi[1])

print(ans)
