t = int(input())
for i in range(t):
    n = int(input())
    k0 = 0
    k1 = 0
    k2 = 0
    for j in list(map(int,input().split())):
        if j%3 == 0:
            k0 += 1
        elif j%3 == 1:
            k1 += 1
        else:
            k2 += 1
    print(k0 + min(k1,k2) + (k1-min(k1,k2))//3 + (k2-min(k1,k2))//6)