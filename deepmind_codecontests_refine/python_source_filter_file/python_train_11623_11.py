V1, V2, V3, Vm = map(int, input().split())

v = [[0, 200] for i in range(3)]

v[0][0], v[1][0], v[2][0] = max(V1, 2 * Vm + 1), max(V2, 2 * Vm + 1), max(V3, Vm)

v[0][1], v[1][1], v[2][1] = 2 * V1, 2 * V2, min(2 * V3, 2 * Vm)

if not (
    (V1 >= v[0][0] and v[0][1] <= 2 * V1) and (V2 >= v[1][0] and v[1][1] <= 2 * V2) and (
    V3 >= v[2][0] and v[2][1] <= 2 * V3) and (v[0][0] <= v[0][1] and v[1][0] <= v[1][1] and v[2][0] <= v[2][1])):
    print(-1)

else:
    ans = [v[0][1]]
    last = v[0][1]

    if v[1][0] <= last:
        ans.append(min(v[1][1], last))
        last = min(v[1][1], last)
    else:
        print(-1)
        exit()

    if v[2][0] <= last:
        ans.append(min(v[2][1], last))
    else:
        print(-1)
        exit()

    print('\n'.join(map(str, ans)))
