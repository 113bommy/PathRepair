N = int(input())
A = sorted(list(map(int,input().split())))

ans_list = []
p = []
n = []

# 最大にプラス、最小にマイナスを割り当てる
p.append(A[-1])
n.append(A[0])

# 正ならプラスを負ならマイナスを割り当てる
for a in A[1:-1]:
    if a >= 0:
        p.append(a)
    elif a < 0:
        n.append(a)

# プラスが１つになるまで消す
while len(p) != 1:
    x = n.pop()
    y = p.pop()
    n.append(x-y)
    ans_list.append((x, y))

# マイナスがなくなるまで消す
while len(n) != 0:
    x = p.pop()
    y = n.pop()
    p.append(x-y)
    ans_list.append((x,y))

# 残ったものが最大値
M = p[0]
print(M)
for ans in ans_list:
    print(ans)