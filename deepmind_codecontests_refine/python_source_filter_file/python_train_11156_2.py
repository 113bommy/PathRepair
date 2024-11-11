n = int(input())
if n < 3:
    print(-1)
else :
    prime = [1 for i in range(2001)]
    p = 2
    while (p*p <= 2000):
        if prime[p] == True:
            for i in range(p*p, 2001, p):
                prime[i] == 0
        p += 1
    length = n
    for i in range(n,2001):
        if prime[i] == 1:
            length = i
            break
    print(length)
    for i in range(n-1):
        print(i+1,i+2)
    print(n,1)
    for i in range(length-n+1):
        print(i+1,i+1+n//2)