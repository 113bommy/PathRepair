t = int(input())
for _ in range(t):
    x = int(input())
    n = list(input())
    print(n)
    count = 0
    res = float('inf')
    for i in n:
        if i =='(':
            count += 1
        else:
            count -= 1
        res = min(res,count)
    print(abs(res))

