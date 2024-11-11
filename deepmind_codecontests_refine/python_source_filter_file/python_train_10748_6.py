for _ in range(int(input())):
    n, x = map(int, input().split())
    s = list(map(int, input().split()))

    odd = 0
    eve = 0
    for i in s:
        if 1%2 == 0:
            eve += 1
        else:
            odd += 1
    
    if odd == 0 or (eve == 0 and x % 2 == 0) or (x == n and sum(s)% 2 == 0):
        print('NO')
        
    else:
        print('YES')
