def is_round(s):
    cnt = 0
    li = ['0','00','000','0000']
    if s[0].isnumeric() and s[1:] in li:
        return 1
    else:
        return 0
def find_sum(s):
    li = []
    new_li = []
    zero = ['0','00','000','0000']
    if is_round(s) == 1:
        new_li.append(s)
    else:
        s = list(s)
        for i in range(len(s)):
            li.append(s[i]+'0'*(len(s)-i-1))
        for i in range(len(li)):
            if li[i] not in zero:
                new_li.append(li[i])
    return len(new_li), new_li

for _ in range(int(input())):
    n = input()
    x, li = find_sum(n)
    print(x)
    print(' '.join(li))