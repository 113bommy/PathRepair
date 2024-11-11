t = int(input())
for _ in range(t):
    n, d = [int(i) for i in input().strip().split()]
    piles = [int(i) for i in input().strip().split()]
    sm = piles[0]
    for i in range(1, n):
        if int(d / i) == 0:
            break
        tmp = min(int(d / i), piles[i]) 
        d -= (i * tmp)
        sm += tmp
    print(sm)

