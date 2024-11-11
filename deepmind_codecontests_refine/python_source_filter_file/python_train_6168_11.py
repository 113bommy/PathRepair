from math import ceil

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    s = sorted(input())

    cnt = 0
    for c in s:
        if c == s[0]:
            cnt += 1
        else:
            break
    
    # print(s)
    # print(cnt)
    
    if cnt < k:
        print(s[k-1])
    else:
        print(s[0], end='')
        if n > k:
            rem = set(s[k:])
            if len(rem) > 1:
                print(*s[k:], sep='')
            else:
                print(*(ceil((n-k) / k) * s[k]))
        else:
            print()