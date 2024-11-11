def haha(s):
    cnt = 0
    for i in range(len(s) - 3):
        if s[i:i+4] == 'haha':
            cnt += 1
    return cnt


def solve():
    vars = dict()
    for _ in range(int(input())):
        s = input().split()
        if s[1] == ':=':
            vars[s[0]] = (haha(s[2]), s[2][:3], s[2][-3:])
        else:
            vars[s[0]] = (vars[s[2]][0] + vars[s[4]][0] + haha(vars[s[2]][2] + vars[s[4]][1]), 
                          (vars[s[2]][1] + vars[s[4]][1])[:3],
                          (vars[s[2]][2] + vars[s[4]][2])[-3:])
        # print(vars[s[0]])

    print(vars[s[0]][0])


for _ in range(int(input())):
    solve()
