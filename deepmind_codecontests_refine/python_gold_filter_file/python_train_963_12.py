# cook your dish here
t = int(input())
for _ in range(t):
    n = int(input())
    li = list(map(int, input().split()))
    i = 0
    res = 0 
    cnt = 0 
    while cnt != 2:
        if li.count(i) == 0:
            if cnt == 0:
                res += (2 * i)
            else:
                res += (i)
            cnt = 2
        if li.count(i) >= (2 - cnt):
            i += 1 
            continue
        else:
            cnt += 1
            res += i 
    print(res)