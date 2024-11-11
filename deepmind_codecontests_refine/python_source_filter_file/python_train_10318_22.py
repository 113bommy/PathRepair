def rmap(): return map(int, input().split())
def rlist(): return list(map(int, input().split()))
def rdi(): return int(input())


n = rdi()
line = rlist()
cnt = [0] * 101
once = 0
triple_ind = 0
triple = 0
for elem in line:
    cnt[elem] += 1
    if cnt[elem] == 1:
        once += 1
    elif cnt[elem] == 2:
        once -= 1
    elif cnt[elem] == 3:
        triple = 1
        
if once % 2 == 0:
    print('YES')
    k = 0
    gg = ['A', 'B']
    for elem in line:
        if cnt[elem] == 1:
            print(gg[k], end='')
            k = (k + 1) % 2
        else:
            print('A', end='')
elif triple == 1:
    print('YES')
    k = 0
    gg = ['A', 'B']
    d = 'A'
    for elem in line:
        if cnt[elem] == 1:
            print(gg[k], end='')
            k = (k + 1) % 2
        elif triple == 1 and cnt[elem] >= 3:
            print(gg[k], end='')
            k = (k + 1) % 2
            triple = 0
            d = 'B'
        elif cnt[elem] >= 3:
            print(d, end='')
        else:
            print('A', end='')
else:  
    print('NO')
