n = int(input().split()[0])
a = list(map(int, input().split()))
ch = list(range(1, n + 1))
leader = ch[0]
for ai in a:
    out = (ch.index(leader) + ai) % len(ch)
    leader = ch[out + 1] % len(ch)
    print("{} ".format(ch[out]), end='')
    del ch[out]
    if len(ch) == 0:
        break
