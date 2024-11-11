row_count, P1, P2, P3, T1, T2 = [int(i) for i in input().split()]
res, past_end = 0, 0
for i in range(row_count):
    if not i:
        start, end = [int(j) for j in input().split()]
    else:
        start, end = [int(j) for j in input().split()]
        not_work_time = start - past_end
        if not_work_time - T1 > 0:
            res += T1 * P1
            not_work_time -= T1
        else:
            res += not_work_time * P1
            not_work_time = 0
        if not_work_time - T2 > 0:
            res += T2 * P2
            not_work_time -= T2
        else:
            res += not_work_time * P1
            not_work_time = 0
        if not_work_time:
            res += not_work_time * P3
    work_time = end - start
    res += work_time * P1
    past_end = end
print(res)