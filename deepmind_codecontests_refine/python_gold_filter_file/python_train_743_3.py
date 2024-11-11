

n, k, m, t = map(int, input().split())

for i in range(t):

    a, b = map(int, input().split())

    if a == 0:
        if k > b:
            k = k - b
            n-=b
        else:
            n -= (n-b)
    else:
        if k >= b:
            k+=1
            n+=1
        else:
            n+=1
        
    print(n, k)