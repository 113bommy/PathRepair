n, m = [int(x) for x in input().split()]

if n < m:
    if n % 2 == 0:
        print("Malvika")
    else:
        print("Akshat")
else:
    if m % 2 == 0:
        print("Malvika")
    else:
        print("Akshat")