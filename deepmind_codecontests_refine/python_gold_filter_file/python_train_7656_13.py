def arr_inp():
    return [int(x) for x in input().split()]


n, a = int(input()), arr_inp()
a_dis = sorted(list(set(a)))
sz = len(a_dis)

exp = (sz == 3 and (a_dis[2] - a_dis[1] == a_dis[1] - a_dis[0])) or sz<3
if (exp):
    print('YES')
else:
    print('NO')
