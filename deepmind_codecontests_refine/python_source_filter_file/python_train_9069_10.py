a = [int(x) for x in list(input())]
zero = [0]
one = [0]
ans = []
for v in a:
    if v == 0:
        zero.append(zero[-1]+1)
        ans.append([1,zero[-1]])
        if zero[-1] == 4:
            zero = [0]
    else:
        one.append(one[-1]+1)
        ans.append([3,one[-1]])
        if one[-1] == 2:
            one = [0]
for value in ans:
    print(*value)
