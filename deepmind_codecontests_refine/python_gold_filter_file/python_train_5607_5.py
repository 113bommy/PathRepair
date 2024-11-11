x, y = map(int, input().split())
a_cnt = abs(abs(x) - abs(y))

if x + a_cnt == y:
    print(a_cnt)
elif x + a_cnt == -y:
    print(a_cnt + 1)
elif x - a_cnt == -y:
    print(a_cnt + 1)
else:
    print(a_cnt + 2)
