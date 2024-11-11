t = int(input())


for _ in range(t):
    res = 0
    n, m = map(int, input().split())
    per = [int(i) for i in input().split()]
    for i in range(len(per)):
        res += per[i] / (i + 1) * (i + 1)
    if m == int(res):
        print(res)
    else:
        print('NO')
