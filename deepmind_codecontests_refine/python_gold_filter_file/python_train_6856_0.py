n = int(input())
now = 0
for i in range(1,n+2):
    now += i
    if now >= n:
        x = now-n
        for j in range(1,i+1):
            if j != x:
                print(j)
        exit()