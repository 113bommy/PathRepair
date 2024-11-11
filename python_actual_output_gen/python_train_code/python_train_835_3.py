from sys import stdin, stdout


n = int(stdin.readline())
psze = 41
ans = 0


def trans(s):
    cnt = 0
    
    for i in range(psze):
        if (i < len(s) and s[i] == '1'):
            cnt += (1 << i)
    
    return cnt

n -= 1

for i in range(psze):
    if 1 << i > n:
        break
    
    s = '0' * i + '1'
    cnt = 1
    
    l, r = 0, n + 1
    while (r - l > 1):
        m = (l + r) >> 1
        
        f = bin(m)[2:][::-1]
        
        if (trans(s + f) <= n):
            l = m
        else:
            r = m
    
    ans += (1 << i) * (l + 1)

stdout.write(str(ans))