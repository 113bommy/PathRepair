v = int(input())
vals = list(map(int, input().strip().split()))
mini = min(vals)
minI = -1
for i in range(9):
    if vals[i] == mini:
        miniI = i
tot = v//(min(vals))

num = [str(miniI+1) for i in range(tot)]
remain = v-(vals[miniI]*tot)
# print(num)
if len(num) == 0:
    print(-1)
else:
    if remain > 0:
        for i in range(tot):
            for j in range(8, miniI, -1):
                if vals[miniI] + remain >= vals[j]:
                    num[i] = str(j+1)
                    remain = (vals[miniI] + remain-vals[j])
                    # print(remain, 'r')
                    break
    print(''.join(i for i in num))
                
