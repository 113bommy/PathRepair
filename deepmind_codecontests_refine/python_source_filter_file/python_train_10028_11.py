t = int(input())
for _ in range(t):
    n = int(input())
    sm = 1
    cnt = 1
    if n == 1:
        print(1)
    elif n == 2 or n == 3:
        print(2)
    else:
        for i in range(3,n,2):
            if sm + i < n:
                sm += i
                cnt += 1
            else:
                print(cnt+1)
                break
    
    