N, P = map(int, input().split())
S = input()

if P == 2 or P == 5:
    cnt = 0

    cnt_a = 0
    for s in S[::-1]:
        if int(s) % P == 0:
            cnt_a += 1

        cnt += cnt_a
else:
    r_lst = [0] * P
    r_lst[0] = 1

    cnt = 0
    num = 0

    for i, s in enumerate(S[::-1]):
        num  = (num + int(s) * pow(10, i, P)) % P
        cnt += r_lst[num]

        r_lst[num] += 1


print(cnt)

