n = int(input())
L = []
for i in range(n):
    L.append(int(input()))

# 一场比赛的输家不可能在下一场比赛中获胜
# 那么只要记录每一场的输家就行了
# 第一场比赛有3个人参加,假设三种情况


def notparti(a, b):
    if a != 1 and b != 1:
        return 1
    elif a != 2 and b != 2:
        return 2
    else:
        return 3


def analy(a, b):
    if a != L[0] and b != L[9]:
        return False

    else:
        # 每一论没有参赛的人
        ob = notparti(a, b)
        ok = True
        i = 0
        while i < len(L) and ok:
            if L[i] == ob:
                ok = False
            else:
                ob = notparti(ob, L[i])
                i = i + 1
        return ok


res = analy(1, 2)
if res:
    print("YES")
else:
    print("NO")
