#A1 ~ Aiまでの和 O(logN)
def BIT_query(BIT,idx):
    res_sum = 0
    while idx > 0:
        res_sum += BIT[idx]
        idx -= idx&(-idx)
    return res_sum

#Ai += x O(logN)
def BIT_update(BIT,idx,x):
    while idx <= n:
        BIT[idx] += x
        idx += idx&(-idx)
    return


alps = 'abcdefghijklmnopqrstuvwxyz'

n = int(input())
s = list(input())
char_hd_d = {}
for alp in alps:
    char_hd_d[alp] = [0]*(n+1)

for i, si in enumerate(s):
    BIT_update(char_hd_d[si], i+1, 1)

q = int(input())
ansl = []
for _ in range(q):
    command, a, b = input().split()
    if command == '1':
        i = int(a)
        c = b
        i_char = s[i-1]
        BIT_update(char_hd_d[i_char], i, -1)
        BIT_update(char_hd_d[c], i, 1)
        s[i-1] = c 
    else:
        l,r = int(a),int(b)
        cnt = 0
        for alp in alps:
            if BIT_query(char_hd_d[alp], r) - BIT_query(char_hd_d[alp], l-1) > 0:
                cnt += 1
        ansl.append(cnt)

for a in ansl:
    print(a)            