m = int(input())
a = []
for j in range(m):
    l = input().split()
    l = list(map(int, l))  # 对l里面的每个东西实行int操作，将字符数组转成int数组
    m = l.pop(3)
    #  找到l里最大和最小的数
    l.sort()
    mx = l[0] + l[1] + l[2] - 3
    mn = min(0, l[2] - l[1] - l[0] - 1)

    if (m >= mn) & (m <= mx):
        a.append(1)
    else:
        a.append(0)
for i in range(3):
    if a[i] == 1:
        print("YES")
    else:
        print("NO")
