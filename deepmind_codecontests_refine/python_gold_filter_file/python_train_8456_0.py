t = int(input())
for i in range(t):
    x = int(input())
    k = 3
    for j in range(2, 40):
        if x % k == 0:
            print(x // k)
            break
        else:
            k += 2**j 