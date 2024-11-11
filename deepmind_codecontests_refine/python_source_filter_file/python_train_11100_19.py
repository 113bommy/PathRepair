
pp_num, wins_time = list(map(int, input().split()))
pp = list(map(int, input().split()))

cnt = 0
while cnt != wins_time:
    if pp[0] == max(pp):
        break
    if pp[0] > pp[1]:
        pp = [pp[0]] + pp[2:] + [pp[1]]
        cnt += 1
    else:
        pp = pp[1:] + pp[0:1]
        cnt = 0

print(pp[0])
