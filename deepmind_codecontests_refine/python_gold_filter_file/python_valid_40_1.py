from sys import stdin
input = stdin.buffer.readline

def func():
    pref_up = [mat[0][0]]
    pref_down = [mat[1][0]]

    for i in range(1, m):
        pref_up.append(pref_up[-1] + mat[0][i])
        pref_down.append(pref_down[-1] + mat[1][i])
    rem = 1e10

    for i in range(m):
        rem = min(rem, max(pref_up[-1] - pref_up[i], pref_down[i] - mat[1][i]))

    print(rem)


for _ in range(int(input())):
    m = int(input())
    mat = list()
    mat.append(list(map(int, input().split())))
    mat.append(list(map(int, input().split())))
    func()
