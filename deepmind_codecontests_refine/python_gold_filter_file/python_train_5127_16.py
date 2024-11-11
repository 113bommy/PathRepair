t = int(input())

for i in range(t):
    nk = list(map(int, input().split()))
    n = nk[0]
    k = nk[1]
    
    flag = True

    if n % 2 == 0:
        print(n + k * 2)
        continue
    else:
        for i in range(3, int(n ** 0.5) + 1, 2):
            if n % i == 0:
                print(n + i + 2 * (k - 1))
                flag = False
                break
    if flag:
        print(n +  n + 2 * (k - 1))


