
q = int(input())
 
for _ in range(q):
    n, k = list(map(int, input().split()))
    counter = 0
    for _ in range(max(n,k)):
        z = n % k
        if z == 0:
            n = n // k
            counter += 1
        elif n // k == 0: 
            counter += n
            n = 0
            break
        else:
            n -= z
            counter += z
        if n == 0:
            break
    print(counter)