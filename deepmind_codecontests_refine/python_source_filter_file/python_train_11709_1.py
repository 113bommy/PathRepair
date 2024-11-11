buck = [[0, 0] for i in range(2500)]
m = int(input())
for i in range(m):
    a = int(input())
    ok = True
    br = 1
    for j in range(2500, -1, -1):
        if a & (1 << j):
            if(buck[j][0]):
                a  ^= buck[j][0]
                br ^= buck[j][1]
            else:
                ok = False
                buck[j][0] = a
                buck[j][1] = br | (1 << i)
                break
    if not ok:
        print("0")
    else:
        lst = []
        for j in range(2501):
            if br & (1 << j):
                lst.append(j)
        print(len(lst), end = ' ')
        for j in lst:
            print(j, end = ' ')
        print('\n', end='')
