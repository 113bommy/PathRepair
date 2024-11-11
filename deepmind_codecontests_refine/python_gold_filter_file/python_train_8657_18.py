import itertools
n = int(input())
b = list(map(int, input().split()))
c = sorted(b)
diff = []

for i in range(n-1):
    diff.append(c[i+1]-c[i])
diff_val = diff[:]
diff = itertools.groupby(diff)
diff_list = []
for key, group in diff:
    diff_list.append([key, len(list(group))])


if len(diff_list) == 1:
    print(b.index(c[0])+1)


elif len(diff_list) == 2:
    if diff_list[0][1] == 1:
        print(b.index(c[0])+1)
    elif diff_list[1][1] == 1:
        print(b.index(c[-1])+1)
    elif diff_list[0][1] == 2 and diff_list[0][0] * 2 == diff_list[1][0]:
        print(b.index(c[1])+1)
    elif diff_list[1][1] == 2 and diff_list[1][0] * 2 == diff_list[0][0]:
        print(b.index(c[-2])+1)
    else:
        print(-1)

elif len(diff_list) == 3:
    if diff_list[0][0] == diff_list[2][0] and diff_list[1][1] == 2 and diff_list[1][0] * 2 == diff_list[0][0]:
        x = diff_list[1][0]
        for i in range(len(diff_val)):
            if diff_val[i] == x:
                print(b.index(c[i+1])+1)
                break
    elif diff_list[1][1] == 1:
        if diff_list[0][0] + diff_list[1][0] == diff_list[2][0]:
            x = diff_list[1][0]
            for i in range(len(diff_val)):
                if diff_val[i] == x:
                    print(b.index(c[i])+1)
                    break
        elif diff_list[2][0] + diff_list[1][0] == diff_list[0][0]:
            x = diff_list[1][0]
            for i in range(len(diff_val)):
                if diff_val[i] == x:
                    print(b.index(c[i+1])+1)
                    break
        else:
            print(-1)
    else:
        print(-1)

elif len(diff_list) == 4:
    if diff_list[1][1] == diff_list[2][1] and diff_list[1][1] == 1 and diff_list[0][0] == diff_list[3][0] and diff_list[1][0] + diff_list[2][0] == diff_list[0][0]:
        x = diff_list[1][0]
        for i in range(len(diff_val)):
            if diff_val[i] == x:
                print(b.index(c[i+1])+1)
                break
    else:
        print(-1)
else:
    print(-1)
