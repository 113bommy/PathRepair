T = int(input())
for _ in range(T):
    n, x = map(int, input().split())
    A = sorted(map(int, input().split()), reverse=True)
    
    cur = 0
    for i, a in enumerate(A):
        # cur += a
        cur = (cur*i + a)/(i+1)
        if (x - (cur / (i+1))) > 1e-8:
            break
    else:
        i = n
        
    print(i)