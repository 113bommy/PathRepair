t = int(input())
for z in range(t):
    n = int(input())
    if n%3 == 0:
        print(n//3, n//3)
    elif (n-1)%3 == 0:
        print((n-1)//3 + 1, (n-1)//3)
    else:
        print((n-2)//3, (n-2)//3 + 1)