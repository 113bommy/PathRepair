N, X, M = map(int, input().split())

nxt = X
lst = []
dic = {}

for i in range(M):
    if nxt in dic:
        loop_st = dic[nxt]
        loop_ed = i - 1
        break

    lst.append(nxt)
    dic[nxt] = i

    nxt = (nxt ** 2) % M


v = N - loop_st
q, r = divmod(v, loop_ed - loop_st + 1)

pre_sum = sum(lst[:loop_st])
loop_sum = q * sum(lst[loop_st:])
post_sum = sum(lst[loop_st:loop_st + r])
print(pre_sum + loop_sum + post_sum)