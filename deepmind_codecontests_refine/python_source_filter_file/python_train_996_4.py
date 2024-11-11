#The Monster

a, b = map(int, input().split())
c, d = map(int, input().split())
same_time = 0
coeff = 0
count = 0
if (a % 2 == 0 and b % 2 != 0) and c % 2 == 0 and d % 2 == 0:
    print("-1")
    
elif (a % 2 == 0 and b % 2 == 0) and c % 2 == 0 and d % 2 != 0:
    print("-1")
elif b == d:
    print(a)
else:
    if b > d:
        g = a
        h = b
        i = c
        j = d
    else:
        g = c
        h = d
        i = a
        j = b
    # Think of each scream as just an addition to the last???
    # ab a+b, b+a+a, b+a+a+a....
    new_gh = h
    new_ij = j

    while True:
    # test until one one is larger than the other, then flip
        if new_gh / new_ij == 1:
            print(new_gh)
            break
        if new_gh > new_ij:
            new_ij += i
        if new_gh < new_ij:
            new_gh += g
        count += 1
        if count == 10000:
            print(-1)
            break