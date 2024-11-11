for _ in range(int(input())):
    n = int(input())
    cay = n
    dem = 0
    while n >=10:
        dem +=n//10
        n = n%10 + n/10
    print(int(dem + cay))