n, k = [int(i) for i in input().split()]
s = input()

def beauty (x):
    ret = 0
    cnt = 0
    r = 0

    for l in range(n):

        while r < n and (cnt < k or s[r] != x):
            if s[r] == x:
                cnt += 1
            r += 1
    
        if r == x:
            cnt -= 1
        
        ret = max(ret, r-l)

    return ret

print(max(beauty('a'), beauty('b')))
exit(0)