def seive(n):
    prime = [True for i in range(n+1)]
    p = 2
    while(p*p <= n):
        if prime[p] == True:
            for i in range(p*p,(n+1),p):
                prime[i] = False
        p += 1
    count = 0
    for i in range(6,(n+1)):
        c = 0
        for p in range(2,(i+1)):
            if prime[p]:
                if i%p == 0:
                    c += 1
        if c == 2:
            count += 1
    print(p)
n = int(input().strip())
seive(n)
