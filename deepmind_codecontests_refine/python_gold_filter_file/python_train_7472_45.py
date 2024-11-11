N = int(input())
S = [input() for i in range(N)]

LR = []
for s in S:
    left, right = 0, 0
    for ss in s:
        if ss == "(":
            left += 1
        else:
            if left:
                left -= 1
            else:
                right += 1
    LR.append([left, right])
#print(LR)

plus = []
minus = []
for l, r in LR:
    if l >= r:
        plus.append([l, r])
    else:
        minus.append([l, r])
        
plus.sort(key = lambda x: x[1])
minus.sort(key = lambda x: -x[0])

cnt = 0
for l, r in plus + minus:
    cnt -= r
    if cnt < 0:
        print("No")
        exit()
    cnt += l
        
if cnt == 0:
    print("Yes")
else:
    print("No")