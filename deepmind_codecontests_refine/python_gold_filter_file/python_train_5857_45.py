t = int(input())
for _ in range(t):
    n, r = [int(x) for x in input().split()]
    if(n <= r):
        c = 1
        k = n-1
    else:
        c = 0
        k = r
    c += (k*(k+1))//2
    print(c)