poss = [15, 16, 17, 18, 19, 20]
poss2 = [13, 14, 15]

def test(n):
    flag = False
    for a in poss:
        p = n - a
        for b in poss2:
            if p >= 0 and p % b == 0:
                print('YES')
                flag = True
                break
        if flag:
            break
    if not flag:
        print('NO')

n = int(input())
nn = list(map(int, input().split()))
for x in nn:
    test(x)